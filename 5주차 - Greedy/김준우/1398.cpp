#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int N;

int coins[3] = { 25, 10, 1 };
int memo[100];

void fillBasicMemo() {
    fill(memo, memo + 100, -1);
    memo[0] = 0;
    memo[1] = 1;
    memo[10] = 1;
    memo[25] = 1;
}

int greedy(int price) {
    int ans = INT_MAX;

    if (memo[price] != -1) return memo[price];

    for (int i = 0; i < 3; i++)
        if (coins[i] <= price)
            ans = min(ans, greedy(price - coins[i]) + 1);
    
    memo[price] = ans;
    return ans;
}

int greedier(long long price) {
    int ans = 0;
    while (price > 0) {
        ans += greedy(price % 100);
        price /= 100;
    }
    return ans;
}

int main() {
    long long price;
    fillBasicMemo();

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> price;
        cout << greedier(price) << endl;
    }

    return 0;
}