//17835번: 면접보는 승범이네

#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
using namespace std;

#define MAX_N 100'000
#define INF 1e11

typedef long long ll;
typedef pair<ll, int> pli;

vector<pli> graph[MAX_N + 2];
ll minDist[MAX_N + 2];

void dijkstra(int start) {
    priority_queue<pli, vector<pli>, greater<>> pq;

    for (int i = 1; i <= MAX_N + 1; i++) minDist[i] = INF;
    minDist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int crNode = pq.top().second;
        ll crWeight = pq.top().first;
        pq.pop();

        if (crWeight > minDist[crNode]) continue;

        for (int i = 0; i < graph[crNode].size(); i++) {
            int nextNode = graph[crNode][i].first;
            ll nextWeight = crWeight + graph[crNode][i].second;

            if (nextWeight < minDist[nextNode]) {
                minDist[nextNode] = nextWeight;
                pq.push({ nextWeight, nextNode });
            }
        }
    }

    return;
}

int main() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    //인접리스트 만들기
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[v].push_back({ u, w }); //도로 방향 뒤집어서 저장
    }

    //가상의 도시로부터 면접장으로 가는 가중치 0인 간선 추가
    for (int i = 0; i < k; i++) {
        int u;
        scanf("%d", &u);
        graph[n + 1].emplace_back(u, 0);
    }

    dijkstra(n + 1);

    int ans = 1;
    for (int u = 2; u <= n; u++) {
        if (minDist[u] > minDist[ans]) ans = u;
    }

    printf("%d\n%lld", ans, minDist[ans]);

    return 0;
}