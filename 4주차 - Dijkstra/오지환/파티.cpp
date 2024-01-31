#include <iostream>
#include <queue>
#include <climits>

#define MAX_V 1000
#define MAX_E 10000
#define INF INT_MAX

using namespace std;

int n, m, x;
vector<pair<int, int>> graph[MAX_V + 1];
int goingTime[MAX_V + 1], comingTime[MAX_V + 1];

void calcComingTime() { // 파티 후 돌아오는 시간 계산
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> container;

    for (int j = 1; j <= n; j++)
        comingTime[j] = INF;

    container.emplace(0, x);
    comingTime[x] = 0;

    while (!container.empty()) {
        int cur_v = container.top().second;
        int cur_dist = container.top().first;
        container.pop();

        if (cur_dist > comingTime[cur_v]) continue;

        for (pair<int, int> next_info : graph[cur_v]) {
            int next_v = next_info.second;
            int next_w = next_info.first;
            if (comingTime[next_v] > comingTime[cur_v] + next_w) {
                comingTime[next_v] = comingTime[cur_v] + next_w;
                container.emplace(comingTime[next_v], next_v);
            }
        }
    }
}

int getMaxStudentTime() {
    int maxStudentTime = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> container;

    calcComingTime();

    // 파티에 참석하러 가는 시간 계산
    for (int i = 1; i <= n; i++) {
        // goingTime 초기화
        for (int j = 1; j <= n; j++)
            goingTime[j] = INF;

        container.emplace(0, i);
        goingTime[i] = 0;

        while (!container.empty()) {
            int cur_v = container.top().second;
            int cur_dist = container.top().first;
            container.pop();

            if (cur_dist > goingTime[cur_v]) continue;

            for (pair<int, int> next_info : graph[cur_v]) {
                int next_v = next_info.second;
                int next_w = next_info.first;
                if (goingTime[next_v] > goingTime[cur_v] + next_w) {
                    goingTime[next_v] = goingTime[cur_v] + next_w;
                    container.emplace(goingTime[next_v], next_v);
                }
            }
        }  

        // 가는 시간과 오는 시간의 합이 가장 큰 학생을 구함
        if (goingTime[x] + comingTime[i] > maxStudentTime)
            maxStudentTime = goingTime[x] + comingTime[i];
    }

    return maxStudentTime;
}

int main() {
    int start, end, maxStudentTime = -1;
    
    cin >> n >> m >> x;

    for (int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    maxStudentTime = getMaxStudentTime();

    cout << maxStudentTime;

    return 0;
}