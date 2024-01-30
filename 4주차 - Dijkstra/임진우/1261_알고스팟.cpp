#include <iostream>
#include <vector>
#include <queue>

#define INF 1000
using namespace std;
typedef pair<int, int> PII;

queue<PII> container;	
int maze[100][100];
int dist[100][100];
int n, m;

void Dijkstra()		
{
	container.emplace(0, 0);
    dist[0][0] = 0;
	
    int drow[4] = {1, -1, 0, 0};
    int dcol[4] = {0 , 0, 1, -1};
    while(!container.empty())
    {
        int cur_row = container.front().first;
        int cur_col = container.front().second;
		container.pop();
        for(int i=0; i<4; i++)
        {
            int next_row = cur_row + drow[i];
            int next_col = cur_col + dcol[i];
            if(next_row >= 0 && next_row < n && next_col >= 0 && next_col < m)
            {
                if(dist[next_row][next_col] > dist[cur_row][cur_col] + maze[next_row][next_col])
                {
                    dist[next_row][next_col] = dist[cur_row][cur_col] + maze[next_row][next_col];
                    container.emplace(next_row, next_col);
                }
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d", &maze[i][j]);
            dist[i][j] = INF;
        }
    }
    Dijkstra();
    cout << dist[n - 1][m - 1];
}   