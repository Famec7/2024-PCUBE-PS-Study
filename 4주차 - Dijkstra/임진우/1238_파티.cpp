#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define MAX 1001
using namespace std;

typedef pair<int, int> PII;

int N, M, X;
int start_v, end_v, t;
int start_loc, des_loc;
vector<PII> graph[MAX];
int t_all[MAX];
vector<int> t_result;

void Init_t_all()
{
    for(int i=0; i<MAX; i++)
        t_all[i] = INF;
}

void Set_t_all(int start_point, int end_point)
{
    t_all[start_point] = 0;
    priority_queue <PII, vector<PII>, greater<>> pri_q;
    pri_q.emplace(0, start_point);
    while(!pri_q.empty())
	{
		int cur_t = pri_q.top().first;
		int cur_point = pri_q.top().second;
        pri_q.pop();
		if(cur_point == end_point)
			continue;
        if(cur_t > t_all[cur_point])
            continue;
		for(PII next : graph[cur_point])
		{
			int next_point = next.second;
			int next_t = next.first;
			if(t_all[next_point] > t_all[cur_point] + next_t)
			{
				t_all[next_point] = t_all[cur_point] + next_t;
				pri_q.emplace(next_t, next_point);
			}
		}
	}
}

void Dijkstra(int start_point, int end_point)
{
    int sum_t = 0;
    Init_t_all();
    Set_t_all(start_point, end_point);
    sum_t += t_all[end_point];
    Init_t_all();
    Set_t_all(end_point, start_point);
    sum_t += t_all[start_point];
    t_result.emplace_back(sum_t);
}

int main()
{
    cin >> N >> M >> X;
    for(int i=0; i<M; i++)
    {
        cin >> start_v >> end_v >> t;
        graph[start_v].emplace_back(t, end_v);
    }
    for(int i=1; i<=N; i++)
    {
        Dijkstra(i, X);
    }
    int max = 0;
    for(int i : t_result)
    {
        if(i > max)
            max = i;
    }
    cout << max;
}