#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int sum = 0;
vector<int> plus_arr;
vector<int> minus_arr;

void Sum_Walking(vector<int> arr, int rest)
{
    int index;
    if(rest == 0)
        index = m - 1;
    else
        index = rest - 1;
    while(index < arr.size())
    {
        
        sum += 2 * arr[index];
        index += m;
    }
}

int main()
{
    int book_loc;
    int plus_max = 0;
    int minus_max = 0;
    cin >> n >> m;
    if(n == 1)
    {
        int k;
        cin >> k;
        cout << abs(k);
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        cin >> book_loc;
        if (book_loc > 0)
            plus_arr.push_back(book_loc);
        else
            minus_arr.push_back(-book_loc);
    }
    if(plus_arr.size() != 0)
    {
        sort(plus_arr.begin(), plus_arr.end());
        int plus_rest = plus_arr.size() % m;
        plus_max = plus_arr.back();
        Sum_Walking(plus_arr, plus_rest);
    }
    if(minus_arr.size() != 0)
    {
        sort(minus_arr.begin(), minus_arr.end());
        int minus_rest = minus_arr.size() % m;
        minus_max = minus_arr.back();
        Sum_Walking(minus_arr, minus_rest);
    }
    if(plus_max > minus_max)
        sum -= plus_max;
    else
        sum -= minus_max;
    cout << sum;
}