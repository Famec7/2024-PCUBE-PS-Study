//13907번: 세금

#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
using namespace std;

#define MAX_DIST (2*1e9)
#define MAX_N 1'000
#define MAX_K 30'000

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

vector<pii> graph[MAX_N + 1];
int minDist[MAX_N + 1][MAX_N + 1];

struct Info {
    int node, cnt, dist;
};

struct compare {
    bool operator()(const Info &a, const Info &b) {
        return a.dist > b.dist;
    }
};

int n, m, k, s, d, tax[MAX_K + 1];

void dijkstra(int start) {
    priority_queue<Info, vector<Info>, compare> pq;

    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 0; j <= MAX_N; j++) minDist[i][j] = MAX_DIST;
    }

    minDist[start][0] = 0;
    pq.push({ start, 0, 0 });

    while (!pq.empty()) {
        int crNode = pq.top().node;
        int crCnt = pq.top().cnt;
        int crDist = pq.top().dist;
        pq.pop();

        if (crCnt >= n) continue;
        if (crDist > minDist[crNode][crCnt]) continue;

        for (int i = 0; i < graph[crNode].size(); i++) {
            int nextNode = graph[crNode][i].first;
            int nextCnt = crCnt + 1;
            int nextDist = crDist + graph[crNode][i].second;

            if (nextDist < minDist[nextNode][nextCnt]) {
                minDist[nextNode][nextCnt] = nextDist;
                pq.push({ nextNode, nextCnt, nextDist });
            }
        }
    }

    return;
}

int main() {

    scanf("%d %d %d %d %d", &n, &m, &k, &s, &d);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    tax[0] = 0;
    for (int i = 1; i <= k; i++) {
        int tmp;
        scanf("%d", &tmp);
        tax[i] = tax[i - 1] + tmp;
    }

    dijkstra(s);

    for (int i = 0; i <= k; i++) {
        int ans = MAX_DIST;
        for (int j = 0; j < n; j++) {
            ans = min(ans, minDist[d][j] + tax[i] * j);
        }
        printf("%d\n", ans);
    }


    return 0;
}