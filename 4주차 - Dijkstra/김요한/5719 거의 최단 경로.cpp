//시간초과

#include<iostream>
#include<math.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

//5719 거의 최단 경로



typedef pair<int, int> PII;

int N, M;
int S, D;
int original_map[500][500];
int controlled_map[500][500];

int shortest;
vector<PII> memory;

void clear_map();
int Dijkstra(int map[][500]);
void DFS(int x, int w, int *visit);
void printmap(int map[][500]) {
	cout << "   ";
	for (int i = 0; i < N; i++)
		cout << i << " ";
	cout << endl<<endl;
	for (int i = 0;i < N; i++) {
		cout << i << "  ";
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			return 0;
		cin >> S >> D;
		for (int i = 0;i < M; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			original_map[u][v] = p;
			controlled_map[u][v] = p;
		}
		
		//printmap(original_map);
		shortest = Dijkstra(original_map);
		int visit[500] = { 0, };
		DFS(S, 0, visit);
		//printmap(controlled_map);
		cout << Dijkstra(controlled_map)<<endl;
		clear_map();
	}
}

void clear_map() {
	for (int i = 0;i < N; i++) {
		for (int j = 0; j < N; j++) {
			original_map[i][j] = 0;
			controlled_map[i][j] = 0;
		}
	}
}

int Dijkstra(int map[][500]) {
	int dist[500]; //각 정점 최단거리
	priority_queue<PII, vector<PII>, greater<>> container; //거리 , 정점
	
	//1.거리 최대값 설정
	for (int i = 0;i < N;i++) {
		dist[i] = 500000;
	}

	dist[S] = 0;

	container.emplace(dist[S], S);
	//3.
	while (not container.empty()) {

		int cur_v = container.top().second;
		int cur_dist = container.top().first;
		container.pop();

		if (cur_dist > dist[cur_v]) continue;
		for (int i = 0; i < N; i++) {
			if (map[cur_v][i] > 0) {
				if (map[cur_v][i] + cur_dist < dist[i]) {
					dist[i] = map[cur_v][i] + cur_dist;
					container.emplace(dist[i], i);
				}
			}
		}
	}
	if (dist[D] != 500000)
		return dist[D];
	else
		return -1;
}





void DFS(int x , int w, int *visit) {
	visit[x] = 1;
	if (x == D && w == shortest) {
		for (int i = 0; i < memory.size(); i++) {
			int x = memory[i].first;
			int y = memory[i].second;
			controlled_map[x][y] = 0;
		}
	}
		
	for (int i = 0; i < N; i++) {
		if (original_map[x][i] != 0 && visit[i] == 0) {
			//cout << "DFS(" << i << "," << w << "+" << map[x][i] << ")" << endl;
			memory.push_back(make_pair(x,i));
			DFS(i, w + original_map[x][i], visit);
			memory.pop_back();
			visit[i] = 0;
		}
	}
}



