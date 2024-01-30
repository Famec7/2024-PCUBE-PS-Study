//20183번: 골목 대장 호석 - 효율성 2

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
using namespace std;

#define INF (1*1e16)
#define MAX_N 100'000
#define MAX_SHAME 1'000'000'001

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

typedef struct info {
    int node;
    int shame;
    ll dist;
} Info;

struct compare {
    bool operator()(const Info &a, const Info &b) {
        if (a.shame == b.shame) return a.dist > b.dist;
        return a.shame > b.shame;
    }
};

ll c;
vector<pil> graph[MAX_N + 1];
int minShame[MAX_N + 1];
ll minDist[MAX_N + 1];

void dijkstra(int start, int end) {
    priority_queue<Info, vector<Info>, compare> pq;

    for (int i = 1; i <= MAX_N; i++) {
        minDist[i] = INF;
        minShame[i] = MAX_SHAME;
    }
    minShame[start] = 0;
    minDist[start] = 0;
    pq.push({ start, 0, 0 });

    while (!pq.empty()) {
        int crNode = pq.top().node;
        int crShame = pq.top().shame;
        ll crDist = pq.top().dist;
        pq.pop();

        if (crNode == end) return;

        if (crDist > minDist[crNode]) continue;

        for (int i = 0; i < graph[crNode].size(); i++) {
            int nextNode = graph[crNode][i].first;
            int nextWeight = graph[crNode][i].second;
            ll nextDist = crDist + nextWeight;
            int nextShame = max(crShame, nextWeight);

            if (nextShame >= minShame[nextNode]) continue;
            if (nextDist > c) continue;

            minDist[nextNode] = nextDist;
            minShame[nextNode] = min(minShame[nextNode], nextShame);
            pq.push({ nextNode, nextShame, nextDist });
        }
    }

    return;
}

int main() {

    int n, m, s, e;
    scanf("%d %d %d %d %lld", &n, &m, &s, &e, &c);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    dijkstra(s, e);

    if (minDist[e] >= INF) printf("-1");
    else printf("%d", minShame[e]);

    return 0;
}