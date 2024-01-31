#include<iostream>
#include<math.h>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

//1238 파티
typedef pair<int, int> PII;

int N, M, X;
int map[1001][1001];
int dist[1001];
int reverse_dist[1001];
void input();
void reverse_Dijkstra(int* dist);
void Dijkstra(int* dist);
void output() {
	int sum_dist[1001];
	for (int i = 1; i <= N; i++) {
		sum_dist[i] = dist[i] + reverse_dist[i];
	}
	cout << *max_element(sum_dist, sum_dist + N + 1);
}

int main() {
	input();

	Dijkstra(dist);
	reverse_Dijkstra(reverse_dist);
	output();
	return 0;
}

void input() {
	cin >> N >> M >> X;
	for (int i = 0; i < M;i++) {
		int u, v, p;
		cin >> u >> v >> p;
		map[u][v] = p;
	}
}

void Dijkstra(int* dist) {

	priority_queue<PII, vector<PII>, greater<>> container; //거리 , 정점

	//1.거리 최대값 설정
	for (int i = 1;i <= N;i++) {
		dist[i] = 100000000;
	}

	dist[X] = 0;
	container.emplace(dist[X], X);

	while (not container.empty()) {

		int cur_v = container.top().second;
		int cur_dist = container.top().first;
		container.pop();

		if (cur_dist > dist[cur_v]) continue;

		for (int i = 1; i <= N; i++) {
			if (map[cur_v][i] > 0) {
				if (map[cur_v][i] + cur_dist < dist[i]) {
					dist[i] = map[cur_v][i] + cur_dist;
					container.emplace(dist[i], i);

				}
			}
		}
	}
}
void reverse_Dijkstra(int* dist) {

	priority_queue<PII, vector<PII>, greater<>> container; //거리 , 정점

	//1.거리 최대값 설정
	for (int i = 1;i <= N;i++) {
		dist[i] = 100000000;
	}

	dist[X] = 0;
	container.emplace(dist[X], X);

	while (not container.empty()) {

		int cur_v = container.top().second;
		int cur_dist = container.top().first;
		container.pop();

		if (cur_dist > dist[cur_v]) continue;

		for (int i = 1; i <= N; i++) {
			if (map[i][cur_v] > 0) {
				if (map[i][cur_v] + cur_dist < dist[i]) {
					dist[i] = map[i][cur_v] + cur_dist;
					container.emplace(dist[i], i);

				}
			}
		}
	}
}

