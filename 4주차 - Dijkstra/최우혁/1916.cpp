#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
#define MAX_V 10001
#define MAX_E 300000
int dist[MAX_V + 1];
vector<PII> graph[MAX_V + 1];

#define INF 100000000
void Dijkstra(int start)
{
    priority_queue<PII, vector<PII>, greater<>> container;
    container.emplace(0, start);
    while (not container.empty())
    {
        int cur_v = container.top().second;
        int cur_dist = container.top().first;
        container.pop();
        if (cur_dist > dist[cur_v]) continue;
        for (PII next_info : graph[cur_v])
        {
            int next = next_info.second;
            int w = next_info.first;

            if (dist[next] > dist[cur_v] + w)
            {
                dist[next] = dist[cur_v] + w;
                container.emplace(dist[next], next);
            }
        }
    }
}
int main()
{
    int n, m, dest, start;

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }
    for (int& i : dist)
        i = INF;

    cin >> start >> dest;
    dist[start] = 0;
    Dijkstra(start);
    cout << dist[dest];
}
