#include <iostream>
#include <queue>
#include <climits>

#define MAX_V 1000
#define MAX_E 100000
#define INF INT_MAX

using namespace std;

int n, m;
vector<pair<int, int>> graph[MAX_V + 1];
int dist[MAX_V + 1];

int getMinCost(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> container;

    for (int i = 0; i <= n; i++)
        dist[i] = INF;

    container.emplace(0, start);
    dist[start] = 0;

    while (!container.empty()) {
        int cur_v = container.top().second;
        int cur_dist = container.top().first;
        container.pop();

        if (cur_dist > dist[cur_v]) continue;

        for (pair<int, int> next_info : graph[cur_v]) {
            int next_v = next_info.second;
            int next_w = next_info.first;
            if (dist[next_v] > dist[cur_v] + next_w) {
                dist[next_v] = dist[cur_v] + next_w;
                container.emplace(dist[next_v], next_v);
            }
        }
    }

    return dist[end];
}

int main() {
    int start, end, min_cost = -1;
    
    cin >> n;
    cin >> m;

    for (int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    cin >> start >> end;

    min_cost = getMinCost(start, end);

    cout << min_cost;

    return 0;
}