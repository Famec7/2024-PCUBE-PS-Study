#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define MAX 100001
using namespace std;

typedef pair<int, int> PII;

int N, M;
int start_bus, end_bus, cost;
int start_loc, end_loc;
vector<PII> graph[MAX];
int cost_all[MAX];

void Init_cost_all()
{
    for(int i=0; i<MAX; i++)
        cost_all[i] = INF;
}

void Dijkstra()
{
    priority_queue <PII, vector<PII>, greater<>> pri_q;
    pri_q.emplace(0, start_loc);
    while(!pri_q.empty())
	{
		int cur_cost = pri_q.top().first;
		int cur_loc = pri_q.top().second;
        pri_q.pop();
		if(cur_loc == end_loc)
			continue;
        if(cur_cost > cost_all[cur_loc])
            continue;
		for(PII next : graph[cur_loc])
		{
			int next_loc = next.second;
			int next_cost = next.first;
			if(cost_all[next_loc] > cost_all[cur_loc] + next_cost)
			{
				cost_all[next_loc] = cost_all[cur_loc] + next_cost;
				pri_q.emplace(next_cost, next_loc);
			}
		}
	}
}

int main()
{
    Init_cost_all();
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        cin >> start_bus >> end_bus >> cost;
        graph[start_bus].emplace_back(cost, end_bus);
    }
    cin >> start_loc >> end_loc;
    cost_all[start_loc] = 0;
    Dijkstra();
    cout << cost_all[end_loc];
}