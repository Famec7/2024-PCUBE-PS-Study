#include<iostream>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;



int N, M;
int map[1001][1001];
int visit[1001];
int cnt = 0;


void BFS(int x) {
	visit[x] = 1;
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (map[x][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}


	for (int i = 1;i <= N; i++) {
		if (visit[i] == 0) {
			BFS(i);
			cnt++;
		}
	}
	cout << cnt;
}



