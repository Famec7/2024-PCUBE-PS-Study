#include<stack>
#include<queue>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int maze[101][101];
int visit[101][101];

// 이동할 네가지 방향 (상, 하, 좌, 우)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int BFS(int x, int y) {
    visit[0][0] = 1;
    queue<pair<int, int>> q; //한 곳에 2개를 저장하는 큐 생성
    q.push({x, y});//푸쉬도 2개
    // 큐가 빌 때까지 반복
    while (not q.empty()) {
        int x = q.front().first;//첫번째 수는 x
        int y = q.front().second;//두번째 수는 y
        q.pop();
        // 현재 위치에서 4가지 방향으로 확인
        for (int i = 0; i < 4; i++) {//4가지 방향으로 확인
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 미로 공간을 벗어난 경우 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
                // 이동할 수 없는 칸이거나  경우 무시
            else if (maze[nx][ny] == 0 || visit[nx][ny] == 1) {
                continue;
            }
                // 처음 방문 & 이동 가능
            else {
                maze[nx][ny] = maze[x][y] + 1;
                visit[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    // 가장 오른쪽 아래까지의 최단 거리 반환
    return maze[n - 1][m - 1];
}

int main() {
    cin >> n >> m; // 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
    cout << BFS(0, 0); //출력
    return 0;
}