#include<stack>
#include<queue>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int board[101][101];//그래프 관계 저장
int visited[101];//bfs에서 방문 저장, 메모리 줄이기
int kin[101];//촌수 저장


void bfs(int a, int n) {
    queue<int> q;//큐 저장
    int i, k;
    q.push(a);
    kin[a] = 0;//a의 촌수 0으로 저장
    while (not q.empty()) {//q만큼 반복
        k = q.front();
        q.pop();
        for (i = 1; i <= n; i++) {
            if (board[k][i] == 1 && visited[i] == 0) {//만약 k와 i의 그래프가 연결되어 있고 방문이 처음일 경우
                q.push(i);
                kin[i] = kin[k] + 1; // 해당 조건을 만족할 때마다 촌수가 1씩 늘어난다.
                visited[i] = 1;//방문 1로 변경
            }
        }
    }
}
int main() {
    int n, m, a, b, x, y, i=0;
    cin >> n;
    cin >> a >> b;
    cin >> m;
    while (i < m) {
        i++;
        cin >> x >> y;
        board[x][y] = 1;  // 가족간의 연결관계 표시
        board[y][x] = 1;
    }
    bfs(a, n); // 입력값 a에 대하여 촌수계산(bfs 시행)
    if (kin[b] == 0) { // 촌수가 없는 관계라면 -1 출력
        cout << "-1\n";
    }
    else {
        cout << kin[b]; // 촌수가 있는 관계라면 촌수 출력
        return 0;
    }
}