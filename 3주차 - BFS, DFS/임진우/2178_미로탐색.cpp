#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int row, col;

    cin >> row >> col;
    int arr[101][101];
    int count[101][101];
	for(int i=0; i<=100; i++)
	{
		for(int j=0; j<=100; j++)
		{
			arr[i][j] = count[i][j] = 0;	
		}
	}
    int cur_row = 0;
    int cur_col = 0;
    for (int i=0; i<row; i++)
    {
        char str[101];
		for(int j=0; j<=100; j++)
		{
			str[j] = 0;
		}
        cin >> str;
        for (int j=0; j<col; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
    queue<pair<int, int>> my_queue;

    my_queue.push({0, 0});
    count[0][0] = 1;
    pair<int, int> cur_coordinate;
    while(count[row - 1][col - 1] == 0)
    {
        cur_coordinate = my_queue.front();
        cur_row = cur_coordinate.first;
        cur_col = cur_coordinate.second;
        my_queue.pop();

        if (cur_row - 1 >= 0 && arr[cur_row - 1][cur_col] && count[cur_row - 1][cur_col] == 0)
        {
            my_queue.push({cur_row - 1, cur_col});
            count[cur_row - 1][cur_col] = count[cur_row][cur_col] + 1;
        }
        if (cur_col - 1 >= 0 && arr[cur_row][cur_col - 1] && count[cur_row][cur_col - 1] == 0)
        {
            my_queue.push({cur_row, cur_col - 1});
            count[cur_row][cur_col - 1] = count[cur_row][cur_col] + 1;
        }
        if (cur_row + 1 < row && arr[cur_row + 1][cur_col] && count[cur_row + 1][cur_col] == 0)
        {
            my_queue.push({cur_row + 1, cur_col});
            count[cur_row + 1][cur_col] = count[cur_row][cur_col] + 1;
        }
        if (cur_col + 1 < col && arr[cur_row][cur_col + 1] && count[cur_row][cur_col + 1] == 0)
        {
            my_queue.push({cur_row, cur_col + 1});
            count[cur_row][cur_col + 1] = count[cur_row][cur_col] + 1;
        }
    }
    cout <<count[row - 1][col - 1];
}
