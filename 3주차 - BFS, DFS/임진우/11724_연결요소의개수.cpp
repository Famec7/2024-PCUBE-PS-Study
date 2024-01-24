#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void BFS(int adjac[1001][1001], vector<int> &vertex_list, int vertex);
int main()
{
	int vertex;
	int edge;
	int ver_first, ver_last;
	int check_size= 0;
	int connected_count;
	int adjac[1001][1001] = {{0}};
	vector<int> vertex_list;

	cin >> vertex >> edge;
	for(int i = 1; i <= vertex; i++)
	{
		vertex_list.push_back(i);
	}
	connected_count = vertex;
	for(int i=0; i<edge; i++)
	{
		cin >> ver_first >> ver_last;
		adjac[ver_first][ver_last] = 1;
		adjac[ver_last][ver_first] = 1;
	}
	for(int element: vertex_list)
	{
		check_size = vertex_list.size();
		BFS(adjac, vertex_list, element);
		if (check_size != vertex_list.size())
			connected_count -= check_size - vertex_list.size();
	}
	cout << connected_count;
}

void BFS(int adjac[1001][1001], vector<int> &list, int vertex)
{
	queue<int> bfs_queue;
	int cur_vertex;
	bfs_queue.push(vertex);
	while(bfs_queue.empty() != true)
	{
		cur_vertex = bfs_queue.front();
		bfs_queue.pop();
		for(int i=1; i<=1000; i++)
		{
			if(adjac[cur_vertex][i] == 1)
			{
				bfs_queue.push(i);
				adjac[cur_vertex][i] = 0;
				adjac[i][cur_vertex] = 0;
				auto to_delete = find(list.begin(), list.end(), i);
				if (to_delete != list.end())
					list.erase(to_delete);
			}
		}
	}
}