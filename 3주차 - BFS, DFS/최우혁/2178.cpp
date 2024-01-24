#include <iostream>
#include <queue>
#include <string>

using namespace std;

int graph[101][101];
int visited[101][101];
int n, m;
int dist = 0;
void miro(int curX, int curY)
{
    visited[curX][curY] = 1;
    queue < pair<int, int>> q;
    q.push(make_pair(curX, curY));
    dist++;
    while (!q.empty()) {


        int x = q.front().first;
        int y = q.front().second;

        int dist = visited[x][y];


        q.pop();

        if (x - 1 != 0 && graph[x - 1][y] && !visited[x - 1][y])
        {
            q.push(make_pair(x - 1, y));
            visited[x - 1][y] = dist + 1;
        }
        if (x + 1 != n + 1 && graph[x + 1][y] && !visited[x + 1][y])
        {
            q.push(make_pair(x + 1, y));
            visited[x + 1][y] = dist + 1;
        }
        if (y - 1 != 0 && graph[x][y - 1] && !visited[x][y - 1])
        {
            q.push(make_pair(x, y - 1));
            visited[x][y - 1] = dist + 1;
        }
        if (y + 1 != m + 1 && graph[x][y + 1] && !visited[x][y + 1])
        {
            q.push(make_pair(x, y + 1));
            visited[x][y + 1] = dist + 1;
        }
    }

}
int main()
{
    cin >> n >> m;
    string input;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
            graph[i][j] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        for (int j = 1; j <= m; j++)
            graph[i][j] = input[j - 1] - 48;
    }

    miro(1, 1);
    cout << visited[n][m];
}