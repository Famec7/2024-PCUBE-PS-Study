#include<iostream>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;

//1261 알고스팟

typedef pair<int, pair<int, int>> PIPII; // 거리 ,x좌표 y좌표
int N, M;
char map[101][102];
int dist[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void input();
void Dijkstra();


int main() {
	
	input();
	Dijkstra();
	cout << dist[N][M];
}


void input() {
	cin >> M >> N;
	for (int i = 1;i <= N;i++) {
		for(int j = 1; j <=M; j++)
			cin >> map[i][j];
	}
}

void Dijkstra() {
	priority_queue<PIPII , vector<PIPII> , greater<>> container;
	
	
	//1.거리 20000으로 할당
	for (int i = 1;i <= N;i++) {
		for (int j = 1; j <= M; j++) {
			dist[i][j] = 20000;
		}
	}
	
	dist[1][1] = 0;
	
	container.emplace(dist[1][1], make_pair(1, 1));
	//3.
	while (not container.empty()) {
		
		int cur_x = container.top().second.first;
		int cur_y = container.top().second.second;
		int cur_dist = container.top().first;
		container.pop();

		if (cur_dist > dist[cur_x][cur_y]) continue;
		for (int i = 0; i < 4;i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x>0 && next_x<=N && next_y>0 && next_y<=M) {
				int next_w = map[next_x][next_y] == '1' ? 1 : 0;
				if (dist[next_x][next_y] > cur_dist + next_w) {
					dist[next_x][next_y] = cur_dist + next_w;
					container.emplace(dist[next_x][next_y], make_pair(next_x, next_y));
				}
			}
		}
	}

}





