#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

char route[101][101] = { 0 };
int dist[101][101] = { 0 };
bool visited[101][101] = { 0 };
int N, M;
int ans = INT_MAX;

void inputRoute() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> route[i][j];
        }
    }
}

void getDistance() {
    queue<pair<int, int>> container;

    container.push(make_pair(0, 0));

    while (!container.empty()) {
        pair<int, int> nowPos = container.front();
        container.pop();

        int i = nowPos.first;
        int j = nowPos.second;

        if (i == N - 1 && j == M - 1) continue;

        if (visited[i][j]) continue;
        visited[i][j] = true;

        if (i > 0)
            if (!visited[i - 1][j] && route[i - 1][j] == '1') {
                container.push(make_pair(i - 1, j));
                dist[i - 1][j] = min(dist[i - 1][j], dist[i][j] + 1);
            }
        if (i < N - 1)
            if (!visited[i + 1][j] && route[i + 1][j] == '1') {
                container.push(make_pair(i + 1, j));
                dist[i + 1][j] = min(dist[i + 1][j], dist[i][j] + 1);
            }
        if (j > 0)
            if (!visited[i][j - 1] && route[i][j - 1] == '1') {
                container.push(make_pair(i, j - 1));
                dist[i][j - 1] = min(dist[i][j - 1], dist[i][j] + 1);
            }
        if (j < M - 1)
            if (!visited[i][j + 1] && route[i][j + 1] == '1') {
                container.push(make_pair(i, j + 1));
                dist[i][j + 1] = min(dist[i][j + 1], dist[i][j] + 1);
            }
        
    }
}

int main() {

    cin >> N >> M;

    fill(&dist[0][0], &dist[N][M], INT_MAX);
    dist[0][0] = 1;

    inputRoute();
    getDistance();

    cout << dist[N - 1][M - 1];


    return 0;
}