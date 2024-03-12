#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long value;
long long answer;
int dp[100] = {0};

void Set_dp()
{
    int n_1;
    int n_10;
    int n_25;
    int min_value;
    dp[0] = 0;
    dp[1] = 1;
    dp[10] = 1;
    dp[25] = 1;
    for(int i=2; i<100; i++)
    {
        min_value = 10000;
        n_25 = i / 25;
        n_10 = (i - n_25 * 25) / 10;
        n_1 = i - n_25 * 25 - n_10 * 10;
        int end_value = n_25;
        for(int j=0; j<=end_value; j++)
        {
            min_value = min(min_value, n_25 + n_10 + n_1);
            n_25--;
            n_10 = (i - n_25 * 25) / 10;
            n_1 = i - n_25 * 25 - n_10 * 10;
        }
        dp[i] = min_value;
    }
}

int main()
{
    cin >> n;
    Set_dp();
    for(int i=0; i<n; i++)
    {
        answer = 0;
        cin >> value;
        while (value) {
            answer += dp[value % 100];
            value /= 100;
		}
        cout << answer << endl;
    }
}