//1162번: 도로포장

#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
using namespace std;

#define INF (1*1e16)
#define MAX_N 10'000

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

vector<pil> graph[MAX_N + 1];
ll dp[MAX_N + 1][21];

typedef struct info {
    int node, cnt;
    ll dist;
} Info;

struct compare {
    bool operator()(const Info &a, const Info &b) {
        return a.dist > b.dist;
    }
};

int k;

void dijkstra(int start, int end) {
    priority_queue<Info, vector<Info>, compare> pq;

    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 0; j <= 20; j++) dp[i][j] = INF;
    }

    dp[start][0] = 0;
    pq.push({ start, 0, 0 });

    while (!pq.empty()) {
        int crNode = pq.top().node;
        int crCnt = pq.top().cnt;
        ll crDist = pq.top().dist;
        pq.pop();

        if (crNode == end) return;

        if (crDist > dp[crNode][crCnt]) continue;

        for (int i = 0; i < graph[crNode].size(); i++) {
            int nextNode = graph[crNode][i].first;
            int nextWeight = graph[crNode][i].second;

            if (crDist < dp[nextNode][crCnt + 1] && crCnt + 1 <= k) {
                dp[nextNode][crCnt + 1] = crDist;
                pq.push({ nextNode, crCnt + 1, crDist });
            }

            if (crDist + nextWeight < dp[nextNode][crCnt]) {
                dp[nextNode][crCnt] = crDist + nextWeight;
                pq.push({ nextNode, crCnt, crDist + nextWeight });
            }
        }
    }

    return;
}

int main() {

    int n, m;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    dijkstra(1, n);

    ll ans = INF;
    for (int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);

    printf("%lld", ans);

    return 0;
}