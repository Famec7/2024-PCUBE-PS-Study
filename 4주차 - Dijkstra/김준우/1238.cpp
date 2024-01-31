#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N, M, X;
int roads[1001][1001];
int dist[1001];
int walkTime[1001];

void inputRoad() {
    int U, V, P;
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> P;
        roads[U][V] = P;
    }
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk;
    dijk.emplace(0, start);
    while (!dijk.empty()) {
        int curDist = dijk.top().first;
        int curCity = dijk.top().second;
        dijk.pop();

        if (curDist > dist[curCity]) continue;
        if (dist[curCity] == INT_MAX) continue;

        for (int i = 1; i < N + 1; i++) {
            if (roads[curCity][i] == 0) continue;
            if (dist[i] > dist[curCity] + roads[curCity][i]) {
                dist[i] = dist[curCity] + roads[curCity][i];
                dijk.emplace(dist[i], i);
            }
        }
    }
    return;
}

int main() {

    cin >> N >> M >> X;
    fill(&dist[0], &dist[N] + 1, INT_MAX);

    inputRoad();

    dist[X] = 0;
    dijkstra(X);

    for (int i = 1; i < N + 1; i++) {
        if (dist[i] != INT_MAX)
            walkTime[i] = dist[i];
    }

    for (int i = 1; i < N + 1; i++) {
        fill(&dist[0], &dist[N] + 1, INT_MAX);
        dist[i] = 0;
        dijkstra(i);
        if (dist[X] != INT_MAX)
            walkTime[i] += dist[X];
    }
    int tmp = INT_MIN;

    for (int i = 1; i < N + 1; i++) {
        tmp = max(walkTime[i], tmp);
    }

    cout << tmp << endl;

    return 0;
}