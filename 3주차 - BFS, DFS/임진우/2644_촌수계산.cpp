#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int num_people;
	int from_a, to_b;
	int num_relation;
	int adjac[101][101] = {{0}};
	int visited_count[101] ={0};

	cin >> num_people >> from_a >> to_b >> num_relation;
	for(int i=0; i<num_relation; i++)
	{
		int person_a, person_b;
		cin >> person_a >> person_b;
		adjac[person_a][person_b] = adjac[person_b][person_a] = 1;
	}

	queue<int> my_queue;
	my_queue.push(from_a);
	int cur;
	while(true)
	{
		if (visited_count[to_b])
		{
			cout << visited_count[to_b];
			return 0;
		}
		else if (my_queue.empty())
		{
			cout << "-1";
			return 0;
		}
		cur = my_queue.front();
		my_queue.pop();
		for(int i=1; i<=num_people; i++)
		{
			if (adjac[cur][i] && visited_count[i] == 0)
			{
				my_queue.push(i);
				visited_count[i] = visited_count[cur] + 1;
			}
		}
	}
}