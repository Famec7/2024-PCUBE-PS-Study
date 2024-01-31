#include<iostream>
#include<math.h>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

//1916 �ּҺ�� ���ϱ�
typedef pair<int, int> PII;

int N, M;
int S, D;
int map[1001][1001];
void input();
int Dijkstra();

int main() {
	memset(map, -1, sizeof(map));
	input();
	cout << Dijkstra();
}

void input() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M;i++) {
		int u, v, p;
		cin >> u >> v >> p;
		if (map[u][v] == -1)
			map[u][v] = p;
		else
			map[u][v] = map[u][v] < p ? map[u][v] : p;
	}
	cin >> S >> D;
}

int Dijkstra() {
	int dist[1001]; //�� ���� �ִܰŸ�
	priority_queue<PII, vector<PII>, greater<>> container; //�Ÿ� , ����
	
	//1.�Ÿ� �ִ밪 ����
	for (int i = 1;i <= N;i++) {
		dist[i] = 100000000;
	}

	dist[S] = 0;
	container.emplace(dist[S], S);

	while (not container.empty()) {

		int cur_v = container.top().second;
		int cur_dist = container.top().first;
		container.pop();

		if (cur_dist > dist[cur_v]) continue;
		for (int i = 1; i <= N; i++) {
			if (map[cur_v][i] != -1) {
				if (map[cur_v][i] + cur_dist < dist[i]) {
					dist[i] = map[cur_v][i] + cur_dist;
					container.emplace(dist[i], i);
				}
			}
		}
	}
	return dist[D];
}









