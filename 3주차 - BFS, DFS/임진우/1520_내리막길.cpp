#include <iostream>
#include <stack>
using namespace std;

int DFS(int rol, int col, int n, int m, int dp[500][500], int height_arr[500][500], bool visited[500][500]);

int main()
{
	int n, m;

	cin >> n >> m;
	int dp[500][500] = {{0}};
	int height_arr[500][500] = {{10001}};
	bool visited[500][500]={{false}};
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> height_arr[i][j];
		}
	}
	cout << DFS(0, 0, n, m, dp, height_arr, visited);
}

int DFS(int row, int col, int n, int m, int dp[500][500], int height_arr[500][500], bool visited[500][500])
{
	if(row == n - 1 && col == m - 1)
	{
		return 1;
	}
	
	if(visited[row][col])
	{
		return dp[row][col];
	}
	visited[row][col] = true;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	for(int i=0; i<4; i++)
	{
		int	next_row = row+dx[i];
		int	next_col = col+dy[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m)
		{
			if (height_arr[next_row][next_col] < height_arr[row][col])
			{
				dp[row][col] = dp[row][col] + DFS(next_row, next_col, n, m, dp, height_arr, visited);
			}
		}
	}
	return dp[row][col];
}