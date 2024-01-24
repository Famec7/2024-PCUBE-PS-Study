#include <iostream>
#include <queue>

#define MAX_N 50
#define MAX_M 50

using namespace std;

int n, m, k;
int map[MAX_N][MAX_M] = { 0 };
int visited[MAX_N][MAX_M] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int x, int y) {
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
                visited[nextY][nextX] = 1;
            }
        }
    }
}

int main() {
    int t, x, y, count = 0;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        count = 0;

        cin >> m >> n >> k;

        for (y = 0; y < n; y++) {
            for (x = 0; x < m; x++) {
                map[y][x] = 0;
                visited[y][x] = 0;
            }
        }

        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            map[y][x] = 1;
        }

        for (y = 0; y < n; y++) {
            for (x = 0; x < m; x++) {
                if (map[y][x] && !visited[y][x]) {
                    BFS(x, y);
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}