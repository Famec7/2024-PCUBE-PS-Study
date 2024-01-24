#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int graph[300][300] = { 0, };
int tmpGraph[300][300] = { 0, };
int visited[300][300] = { 0, };


int dirN[4] = { 0,0,1,-1};
int dirM[4] = { 1,-1,0,0};
int curN, curM;
int year = 0;

void iceberg()
{
	year++;

	queue <pair<int, int>> q;

	q.push(make_pair( curN,curM ));
	visited[curN][curM] = year;

	int cnt = 0;

	while (!q.empty())
	{
		pair<int, int>front = q.front();

		curN = front.first;
		curM = front.second;

		q.pop();
		int minus = 0;
		
		for (int i = 0; i < 4; i++)
		{
			int tmpN = curN + dirN[i];
			int tmpM = curM + dirM[i];

			if (tmpN < 0 || tmpN == N || tmpM < 0 || tmpM == M) continue;
			if (visited[tmpN][tmpM] >= year) continue;
			if (graph[tmpN][tmpM] == 0) {
				minus++;
			}
			else 
			{
				visited[tmpN][tmpM] = year;
				q.push(make_pair( tmpN,tmpM ));
			}
		}

		if (graph[curN][curM] - minus <= 0)
			tmpGraph[curN][curM] = 0;
		else
			tmpGraph[curN][curM] -= minus;

		cnt++;
	}

	bool isDivided = false;
	bool allMeltCheck = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = tmpGraph[i][j];

			if (graph[i][j] != 0) 
			{
				allMeltCheck = false;
				if(visited[i][j] != year)
					isDivided = true;

				curN = i;
				curM = j;
			}
		}
	}

	if (!isDivided && !allMeltCheck)
		iceberg();

	if (allMeltCheck)
		year = 1;
}


int main()
{
	cin >> N >> M;
	bool isSetting = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input;
			cin >> input;
			graph[i][j] = input;
			tmpGraph[i][j] = input;
			if (input != 0 && !isSetting) 
			{
				curN = i;
				curM = j;

				isSetting = true;
			}
		}
	}
	if (isSetting)
		iceberg();

	year--;
	cout << year;
}