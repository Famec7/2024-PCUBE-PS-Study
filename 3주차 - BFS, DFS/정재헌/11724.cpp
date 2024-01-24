#include<stack>
#include<queue>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;


int map[51][51];//농장 크기, 배추 심었는지 확인
int visited[51][51];//농장 방문 확인
int dy[4] = { 0,0,-1,1 };//y축 이동
int dx[4] = { -1,1,0,0 };//x축 이동


void dfs(int y, int x, int a, int b) {//dfs로 이동 경로 확인
    int i, nx, ny;
    visited[y][x] = 1;//방문완료

    for (i = 0; i < 4; i++) {//4번 동서남북 이동하여 배추 찾기
        nx = x + dx[i];//x좌표 이동
        ny = y + dy[i];//y좌표 이동
        if (nx < 0 || nx >= a || ny < 0 || ny >= b)//벗어날경우 경우 생략
            continue;
        else if (map[ny][nx] == 1 && visited[ny][nx] == 0) {//만약 배추가 있고 방문을 안했으면
            dfs(ny, nx, a, b);//dfs, 해당 좌표로 다시 재귀
        }
    }
}

void reset(int a, int b) {//초기화 코드
    int i, j;
    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            map[i][j] = 0;
        }
    }

    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    int n, a, b, c, x, y, i, j, cnt;
    cin >> n;//농장 개수
    while (1) {//무한반복
        if (n == 0) break;//n이 0이면 break;
        n--;//n 1감소
        cin >> a >> b >> c;//농장 가로 세로, 배추 입력
        cnt = 0;//카운트 초기화
        reset(a, b);//농장 초기화
        for (i = 0; i < c;i++) {//c만큼 배추 좌표 입력
            cin >> x >> y;
            map[y][x] = 1;//이때, 배열에 넣을것이므로 배열에 맞게 x, y변경해서 넣기
        }
        for (i = 0; i < b; i++) {//배열에 맞게 반대로 넣었으므로 2중 for문도 반대로 넣기
            for (j = 0; j < a; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {//만약 배추가 있고 방문이 안되어 있으면 dfs진행
                    dfs(i, j, a, b);
                    cnt++;//카운트 추가
                }
            }
        }
        cout <<cnt<<endl;//카운트 출력
    }
}