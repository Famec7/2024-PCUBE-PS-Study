#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int N, M;//�Է� ���� ����
int board[101][101];//���� ����
int dist[101][101];//�� ���� üũ
int dx[4] = { 1, -1, 0, 0 };//x�� �̵�
int dy[4] = { 0, 0, 1, -1 };//y�� �̵�

void bfs() {//bfs�̿�
    int x, y, i, nx, ny;
    queue<pair<int, int>> q;//ť ���
    q.push({ 0,0 });//�� ó�� ����
    dist[0][0] = 0;//�� ó�� 0���� ����

    while (not q.empty()) {//�ݺ���
        x = q.front().first;//�Ǿ� ���ҷ� x, y �Է¹ޱ�
        y = q.front().second;
        q.pop();//�� �� ���� ����
        for (i = 0; i < 4; i++) {//�����¿�
            nx = x + dx[i];//�̵��� ��ǥ �̵�
            ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;//���� ���� ����� ���� �ʱ�
            if (board[nx][ny] == 1) {//���� �̵��ϴ� ���尡 ���̸�
                if (dist[nx][ny] > dist[x][y] + 1) {//���� �Ÿ��� �������� 1�߰��� �Ÿ����� ũ��
                    dist[nx][ny] = dist[x][y] + 1;//�� ���� ����
                    q.push({ nx,ny });//�� �ڿ� �߰�
                }
            }
            else if (board[nx][ny] == 0) {//���� �̵��ϴ� ���尡 ���� ������
                if (dist[nx][ny] > dist[x][y]) {//���� �Ÿ��� �� ũ��
                    dist[nx][ny] = dist[x][y];
                    q.push({ nx,ny });//�� �ڿ� �߰�
                }
            }
        }
    }

}

int main() {
    cin >> N >> M;//���� ũ�� �Է¹ޱ�
    int i, j;
    for (i = 0; i < M; i++) {//���� for��
        for (j = 0; j < N; j++) {
            dist[i][j] = 1000000;//�ִ�ġ ���Ƿ� �ֱ�
            scanf("%1d", &board[i][j]);//�Է¹ޱ�
        }
    }
    bfs();//bfs����
    cout << dist[M - 1][N - 1];//0���� �迭 �����̱⿡ 1�� �����Ͽ� ���
    return 0;
}