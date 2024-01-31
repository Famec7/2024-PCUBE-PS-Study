#include <iostream>
#include <queue>
#include <climits>

#define MAX_N 100
#define MAX_M 100
#define INF INT_MAX

using namespace std;

int m, n;
int map[MAX_N][MAX_M];
int dist[MAX_N][MAX_M];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dijkstra(int start_x, int start_y) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> container;

    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_M; j++)
            dist[i][j] = INF;

    container.emplace(0, make_pair(start_x, start_y));
    dist[start_y][start_x] = 0;

    while (!container.empty()) {
        int cur_x = container.top().second.first;
        int cur_y = container.top().second.second;
        int cur_dist = container.top().first;
        container.pop();

        if (cur_dist > dist[cur_y][cur_x]) continue;

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if ((next_x < 0 || next_x >= m) || (next_y < 0 || next_y >= n)) continue;

            if (dist[next_y][next_x] > cur_dist + map[next_y][next_x]) {
                dist[next_y][next_x] = cur_dist + map[next_y][next_x];
                container.emplace(dist[next_y][next_x], make_pair(next_x, next_y));
            }
        }
    }

    return dist[n - 1][m - 1] / 1000;
}

int main() {
    int ans = -1;
    
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
            if (map[i][j] == 0) map[i][j] = 1;
            else map[i][j] = 1000;
        }
    }

    ans = dijkstra(0, 0);

    cout << ans;

    return 0;
}