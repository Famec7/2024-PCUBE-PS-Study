#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100
#define MAX_M 100
#define MAX_H 100

using namespace std;

int n, m, h;
int map[MAX_H][MAX_N][MAX_M] = { 0 };
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int getTomatoDay() {
    int day = 0;
    queue<tuple<int, int, int>> q;

    // 익은 토마토가 있는 위치를 모두 큐에 삽입
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (map[z][y][x] == 1) {
                    q.push(make_tuple(x, y, z));
                }
            }
        }
    }

    while (!q.empty()) {
        int curX = get<0>(q.front());
        int curY = get<1>(q.front());
        int curZ = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            int nextZ = curZ + dz[i];
            if ((nextX >= 0 && nextX < m) && (nextY >= 0 && nextY < n) && (nextZ >= 0 && nextZ < h)
                && map[nextZ][nextY][nextX] == 0) {
                q.push(make_tuple(nextX, nextY, nextZ));
                map[nextZ][nextY][nextX] = map[curZ][curY][curX] + 1;
            }
        }
    }

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                // 익지 않은 토마토가 남아있다면 토마토가 모두 익지 못하는 상황이므로 -1 반환
                if (map[z][y][x] == 0)
                    return -1;
                // 최대 일수 계산
                if (map[z][y][x] > day)
                    day = map[z][y][x];
            }
        }
    }

    return day - 1;
}

int main() {
    int x, y, z, day = 0;

    cin >> m >> n >> h;

    // 맵 초기화
    for (z = 0; z < h; z++) {
        for (y = 0; y < n; y++) {
            for (x = 0; x < m; x++) {
                map[z][y][x] = 0;
            }
        }
    }
    
    // 맵 정보 입력
    for (z = 0; z < h; z++) {
        for (y = 0; y < n; y++) {
            for (x = 0; x < m; x++) {
                cin >> map[z][y][x];
            }
        }
    }

    day = getTomatoDay();

    cout << day << endl;

    return 0;
}