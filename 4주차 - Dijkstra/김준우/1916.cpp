#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N, M, S, D;
int roads[1001][1001];
int dist[1001];

void inputRoad() {
    int U, V, P;
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> P;
        if (roads[U][V] > P || roads[U][V] == -1)
            roads[U][V] = P;
    }
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk;
    dijk.emplace(0, S);
    while (!dijk.empty()) {
        int curDist = dijk.top().first;
        int curCity = dijk.top().second;
        dijk.pop();

        if (curDist > dist[curCity]) continue;
        if (dist[curCity] == INT_MAX) continue;

        for (int i = 1; i < N + 1; i++) {
            if (roads[curCity][i] < 0) continue;
            if (dist[i] > dist[curCity] + roads[curCity][i]) {
                dist[i] = dist[curCity] + roads[curCity][i];
                dijk.emplace(dist[i], i);
            }
        }
    }
}

int main() {

    cin >> N >> M;
    fill(&dist[0], &dist[N] + 1, INT_MAX);
    fill(&roads[0][0], &roads[N][N] + 1, -1);

    inputRoad();

    cin >> S >> D;
    dist[S] = 0;

    dijkstra();
    cout << dist[D] << endl;

    return 0;
}