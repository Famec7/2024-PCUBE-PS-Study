#include <iostream>
#include <queue>
#include <deque>
#include <climits>

#define MAX_V 1000
#define MAX_E 100000
#define INF INT_MAX

using namespace std;

int n, m;
vector<pair<int, int>> graph[MAX_V + 1];
int dist[MAX_V + 1];
int prev_v[MAX_V + 1];

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
                prev_v[next_v] = cur_v;
            }
        }
    }

    return dist[end];
}

int main() {
    int start, end, min_cost = -1, cur_v;
    deque<int> ans;
    
    cin >> n;
    cin >> m;

    for (int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    cin >> start >> end;

    min_cost = getMinCost(start, end);

    cur_v = end;
    ans.push_front(end);
    while(cur_v != start) {
        ans.push_front(prev_v[cur_v]);
        cur_v = ans.front();
    }

    cout << min_cost << endl;;
    cout << ans.size() << endl;
    for (int v : ans)
        cout << v << " ";
    cout << endl;

    return 0;
}