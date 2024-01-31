#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int M, N;
int maze[101][101];
pair<int, int> dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int wallCnt[101][101];

void inputMaze() {
    char tmp;
    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < M + 1; j++) {
            cin >> tmp;
            maze[i][j] = tmp - '0';
        }
}

void dijkstra() {
    priority_queue<pair<int, int>> dijk;
    dijk.emplace(1, 1);
    while (!dijk.empty()) {
        pair<int, int> cur = dijk.top();
        dijk.pop();

        for (int i = 0; i < 4; i++) {
            int newI = cur.first + dir[i].first;
            int newJ = cur.second + dir[i].second;

            if (newI < 1 || newI > N)
                continue;
            if (newJ < 1 || newJ > M)
                continue;

            if (wallCnt[newI][newJ] > wallCnt[cur.first][cur.second] + maze[newI][newJ]) {
                wallCnt[newI][newJ] = wallCnt[cur.first][cur.second] + maze[newI][newJ];
                dijk.emplace(newI, newJ);
            }
        }
    }
}


int main() {

    cin >> M >> N;
    fill(&wallCnt[0][0], &wallCnt[N][M] + 1, M * N + 1);
    wallCnt[1][1] = 0;

    inputMaze();
    dijkstra();

    cout << wallCnt[N][M];

    return 0;
}