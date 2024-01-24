#include <iostream>
#include <queue>
#include <string>

using namespace std;

int graph[101][101] = { 0, };
int graph2[101][101] = { 0, };
bool visited[101][101];
int n;
int areaCnt = 0;

int dirY[4] = { 0,0,1,-1 };
int dirX[4] = { 1,-1,0,0 };

void bfs(int graph_[][101] ,int y,int x)
{
	areaCnt++;

	queue<pair<int,int>>q;
	q.push(make_pair(y,x));
	visited[y][x] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		int color = graph_[y][x];

		for (int i = 0; i < 4; i++)
		{
			int tmpY = y + dirY[i];
			int tmpX = x + dirX[i];

			if (tmpY < 0 || tmpY == n || tmpX < 0 || tmpX == n) continue;
			if (visited[tmpY][tmpX]) continue;
			int cmpColor = graph_[tmpY][tmpX];

			if (cmpColor == color)
			{
				q.push(make_pair(tmpY, tmpX));
				visited[tmpY][tmpX] = true;

			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j]) {
				bfs(graph_, i, j);
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < n; j++)
		{
			if (input[j] == 'R') {
				graph[i][j] = 1;
				graph2[i][j] = 1;
			}
			else if (input[j] == 'G') {
				graph[i][j] = 2;
				graph2[i][j] = 1;
			}
			else if (input[j] == 'B') {
				graph[i][j] = 3;
				graph2[i][j] = 2;
			}
		}
	}

	bfs(graph,0,0);
	cout << areaCnt << endl;
	areaCnt = 0;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
			visited[i][j] = false;
	}

	bfs(graph2, 0, 0);
	cout << areaCnt << endl;

}