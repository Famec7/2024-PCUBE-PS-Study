//1520번: 내리막 길

#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)

int n, m, arr[500][500], dp[500][500];

int check(int x0, int y0) {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        int x = x0 + dx[i];
        int y = y0 + dy[i];

        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (arr[x][y] > arr[x0][y0]) cnt += dp[x][y];
        }
    }

    if (cnt > dp[x0][y0]) dp[x0][y0] = cnt;
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    dp[0][0] = 1;

    for (int x0 = 0; x0 < n; x0++) {
        for (int y0 = 0; y0 < m; y0++) {
            check(x0, y0);
        }
    }

    int max = n > m ? n : m;

    for (int i = 0; i < (max - 1) / 2; i++) {

        for (int x0 = n - 1; x0 >= 0; x0--) {
            for (int y0 = m - 1; y0 >= 0; y0--) {
                check(x0, y0);
            }
        }

        for (int x0 = 0; x0 < n; x0++) {
            for (int y0 = 0; y0 < m; y0++) {
                check(x0, y0);
            }
        }
    }

    printf("%d", dp[n - 1][m - 1]);

    return 0;
}