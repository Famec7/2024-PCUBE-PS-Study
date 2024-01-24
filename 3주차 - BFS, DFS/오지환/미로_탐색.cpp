#include <iostream>
#include <queue>

#define MAX_N 100
#define MAX_M 100

using namespace std;

int n, m;
int map[MAX_N][MAX_M] = { 0 };
int visited[MAX_N][MAX_M] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int BFS(int x, int y) {
    queue<pair<int, int>> q;

    q.push(pair<int, int>(x, y));
    visited[y][x] = 1;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if (curX == m - 1 && curY == n - 1)
            break;

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if ((nextX >= 0 && nextX < m) && (nextY >= 0 && nextY < n) && visited[nextY][nextX] == 0 && map[nextY][nextX] == 1) {
                q.push(pair<int, int>(nextX, nextY));
                visited[nextY][nextX] = visited[curY][curX] + 1;
            }
        }
    }

    return visited[n - 1][m - 1];
}

int main() {    
    int count = 0;
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            map[i][j] = s[j] - '0';
    }

    count = BFS(0, 0);

    cout << count << endl;

    return 0;
}