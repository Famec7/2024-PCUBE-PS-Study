#include <iostream>
#include <string>
#include <queue>

#define INF 10000000

using namespace std;
int graph[101][101];
int breakCnt = 0;
int dist[101][101];

int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool visited[101][101];

void Dijkstra()
{
	priority_queue<pair<int, int>>container;
	container.emplace(make_pair(1, 1));
	visited[0][0] = true;
	while (!container.empty())
	{
		int curX = container.top().first;
		int curY = container.top().second;
		int curDist = dist[curX][curY];

		container.pop();

		if (curDist > dist[curX][curY]) continue;

		for (int i = 0; i < 4; i++)
		{
			int tmpX = curX + dx[i];
			int tmpY = curY + dy[i];
			int tmpDist = curDist;

			if (tmpX < 0 || tmpY < 0 || tmpX > m || tmpY > n && visited[tmpX][tmpY]) continue;

			tmpDist += graph[tmpX][tmpY];

			if (dist[tmpX][tmpY] > tmpDist) {
				dist[tmpX][tmpY] = tmpDist;
				visited[tmpX][tmpY] = true;
				container.emplace(make_pair(tmpX, tmpY));
			}
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = input[j-1] - 48;
			dist[i][j] = INF;
		}
	}

	dist[1][1] = 0;

	Dijkstra();
	
	cout << dist[m][n];
}
