//24042번: 횡단보도

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
using namespace std;

#define MAX_DIST (7*1e16)
#define MAX_N 100'000

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

int n, m;
vector<pii> graph[MAX_N + 1];
ll minDist[MAX_N + 1];

void dijkstra(int start, int end) {
    priority_queue<pli, vector<pli>, greater<>> pq;

    for (int i = 1; i <= MAX_N; i++) {
        minDist[i] = (ll)MAX_DIST;
    }
    minDist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        ll crDist = pq.top().first;
        int crNode = pq.top().second;
        int crCycle = crDist % m;
        pq.pop();

        if (crNode == end) return;

        if (crDist > minDist[crNode]) continue;

        for (int i = 0; i < graph[crNode].size(); i++) {
            int nextNode = graph[crNode][i].first;
            int nextCycle = graph[crNode][i].second;
            ll nextDist = crDist + (nextCycle - crCycle + m) % m + 1;

            if (nextDist < minDist[nextNode]) {
                minDist[nextNode] = nextDist;
                pq.push({ nextDist, nextNode });
            }
        }
    }

    return;
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back({ v, i });
        graph[v].push_back({ u, i });
    }

    dijkstra(1, n);

    if (minDist[n] >= MAX_DIST) printf("-1");
    else printf("%lld", minDist[n]);

    return 0;
}