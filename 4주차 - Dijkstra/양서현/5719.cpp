//5719번: 거의 최단 경로

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
using namespace std;

#define MAX_N 500
#define INF 100'000

typedef pair<int, int> pii;

unordered_map<int, int> graph[MAX_N + 1];
vector<pii> invGraph[MAX_N + 1];

int minDist[MAX_N + 1];
bool vstd[MAX_N + 1];

void dijkstra(int start) {
    priority_queue<pii> pq;

    minDist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int crNode = pq.top().second;
        int crWeight = -pq.top().first;
        pq.pop();

        for (auto it = graph[crNode].begin(); it != graph[crNode].end(); it++) {
            int nextNode = (*it).first;
            int nextWeight = (*it).second + crWeight;

            if (nextWeight < minDist[nextNode]) {
                minDist[nextNode] = nextWeight;
                pq.push({ -nextWeight, nextNode });
            }
        }
    }
    return;
}

void removeEdges(int start) {
    queue<pii> q;
    vstd[start] = true;

    q.push({ start, 0 });

    while (!q.empty()) {
        int crNode = q.front().first;
        int crWeight = q.front().second;
        q.pop();

        for (int i = 0; i < invGraph[crNode].size(); i++) {
            int nextNode = invGraph[crNode][i].first;
            int nextWeight = invGraph[crNode][i].second + crWeight;

            if (minDist[nextNode] + nextWeight == minDist[start]) {
                graph[nextNode][crNode] = INF;

                if (!vstd[nextNode]) {
                    vstd[nextNode] = true;
                    q.push({ nextNode, nextWeight });
                }

                //printf("%d %d\n", nextNode, crNode);
            }

        }
    }

}

int main() {

    int n, m, s, e;
    scanf("%d %d", &n, &m);
    while (n != 0 && m != 0) {
        for (int i = 0; i < n; i++) { //초기화
            graph[i].clear();
            invGraph[i].clear();
            minDist[i] = INF;
            vstd[i] = false;
        }

        scanf("%d %d", &s, &e);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u][v] = w;
            invGraph[v].push_back({ u, w });
        }

        dijkstra(s);
        removeEdges(e);

        for (int i = 0; i < n; i++) {
            minDist[i] = INF;
        }

        dijkstra(s);

        if (minDist[e] >= INF) printf("-1\n");
        else printf("%d\n", minDist[e]);


        scanf("%d %d", &n, &m);
    }

    return 0;
}