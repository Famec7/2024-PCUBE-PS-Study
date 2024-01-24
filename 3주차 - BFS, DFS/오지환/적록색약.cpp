#include <iostream>
#include <queue>

#define MAX_N 100

using namespace std;

int n;
int map[MAX_N][MAX_N] = { 0 };
int visited[MAX_N][MAX_N] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void areaBFS(int x, int y) {
    queue<pair<int, int>> q;

    q.push(pair<int, int>(x, y));
    visited[y][x] = 1;

    int curColor = map[y][x];

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if ((nextX >= 0 && nextX < n) && (nextY >= 0 && nextY < n) && visited[nextY][nextX] == 0 && map[nextY][nextX] == curColor) {
                q.push(pair<int, int>(nextX, nextY));
                visited[nextY][nextX] = 1;
            }
        }
    }
}

int main() {
    int count = 0, rgCount = 0;

    cin >> n;

    for (int y = 0; y < n; y++) {
        string s;
        cin >> s;
        for (int x = 0; x < n; x++) {
            switch (s[x]) {
            case 'R':
                map[y][x] = 0;
                break;
            case 'G':
                map[y][x] = 1;
                break;
            case 'B':
                map[y][x] = 2;
                break;
            default:
                break;
            }
        }
    }

    // ���ϻ����� �ƴ� ����� ������ �� ������ ���� ����
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (visited[y][x] == 0) {
                areaBFS(x, y);
                count++;
            }
        }
    }

    // ���� = �ʷ����� �׸� ���� ���� & visited ���� �ʱ�ȭ
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            visited[y][x] = 0;
            if (map[y][x] == 1)
                map[y][x] = 0;
        }
    }

    // ���ϻ����� ����� ������ �� ������ ���� ����
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (visited[y][x] == 0) {
                areaBFS(x, y);
                rgCount++;
            }
        }
    }

    cout << count << " " << rgCount << endl;

    return 0;
}