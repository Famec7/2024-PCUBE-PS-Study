#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int height[500][500] = { 0 };
int memo[500][500] = { 0 };
bool visited[500][500] = { 0 };
int N, M;

void inputHeight() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> height[i][j];
        }
    }
}
int getWay(int i, int j) {
    int ans = 0;
    if (i == N - 1 && j == M - 1) {
        return 1;
    }
    if (memo[i][j] != 0) {
        return memo[i][j];
    }

    visited[i][j] = true;

    bool flag = false;
    int result = 0;
    if (i > 0)
        if (!visited[i - 1][j] && height[i - 1][j] < height[i][j]) {
            result = getWay(i - 1, j);
            if (result > 0) {
                ans += result;
                flag = true;
            }
            visited[i - 1][j] = false;
        }
    if (i < N - 1)
        if (!visited[i + 1][j] && height[i + 1][j] < height[i][j]) {
            result = getWay(i + 1, j);
            if (result > 0) {
                ans += result;
                flag = true;
            }
            visited[i + 1][j] = false;
        }
    if (j > 0)
        if (!visited[i][j - 1] && height[i][j - 1] < height[i][j]) {
            result = getWay(i, j - 1);
            if (result > 0) {
                ans += result;
                flag = true;
            }
            visited[i][j - 1] = false;
        }
    if (j < M - 1)
        if (!visited[i][j + 1] && height[i][j + 1] < height[i][j]) {
            result = getWay(i, j + 1);
            if (result > 0) {
                ans += result;
                flag = true;
            }
            visited[i][j + 1] = false;
        }

    if (!flag) {
        memo[i][j] = -1;
        return memo[i][j];
    }

    memo[i][j] = ans;
    return ans;
}

int main() {

    cin >> N >> M;

    inputHeight();

    int tmp = getWay(0, 0);

    if (tmp < 0) tmp = 0;
    cout << tmp;


    return 0;
}