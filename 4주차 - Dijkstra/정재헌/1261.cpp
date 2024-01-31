#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int N, M;//입력 변수 설정
int board[101][101];//갇힌 보드
int dist[101][101];//벽 개수 체크
int dx[4] = { 1, -1, 0, 0 };//x축 이동
int dy[4] = { 0, 0, 1, -1 };//y축 이동

void bfs() {//bfs이용
    int x, y, i, nx, ny;
    queue<pair<int, int>> q;//큐 사용
    q.push({ 0,0 });//맨 처음 설정
    dist[0][0] = 0;//맨 처음 0으로 설정

    while (not q.empty()) {//반복문
        x = q.front().first;//맨앞 원소로 x, y 입력받기
        y = q.front().second;
        q.pop();//맨 앞 원소 삭제
        for (i = 0; i < 4; i++) {//상하좌우
            nx = x + dx[i];//이동한 좌표 이동
            ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;//만약 보드 벗어나면 하지 않기
            if (board[nx][ny] == 1) {//만약 이동하는 보드가 벽이면
                if (dist[nx][ny] > dist[x][y] + 1) {//만약 거리가 이전보다 1추가한 거리보다 크면
                    dist[nx][ny] = dist[x][y] + 1;//벽 개수 변경
                    q.push({ nx,ny });//맨 뒤에 추가
                }
            }
            else if (board[nx][ny] == 0) {//만약 이동하는 보드가 벽이 없으면
                if (dist[nx][ny] > dist[x][y]) {//만약 거리가 더 크면
                    dist[nx][ny] = dist[x][y];
                    q.push({ nx,ny });//맨 뒤에 추가
                }
            }
        }
    }

}

int main() {
    cin >> N >> M;//보드 크기 입력받기
    int i, j;
    for (i = 0; i < M; i++) {//이중 for문
        for (j = 0; j < N; j++) {
            dist[i][j] = 1000000;//최대치 임의로 넣기
            scanf("%1d", &board[i][j]);//입력받기
        }
    }
    bfs();//bfs실행
    cout << dist[M - 1][N - 1];//0부터 배열 시작이기에 1씩 감소하여 출력
    return 0;
}