//1707번: 이분 그래프

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define MAX_V 20000

void dfs(vector<int> *arr, int *color, int *visited, int num, int currColor) {
    color[num] = currColor;
    for (int i = 0; i < arr[num].size(); i++) {
        if (!visited[arr[num][i]]) {
            visited[arr[num][i]] = 1;
            dfs(arr, color, visited, arr[num][i], (currColor + 1) % 2);
        }
    }
    return;
}

int isBipartiteGraph(vector<int> *arr, int *color, int v) {
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (color[i] == color[arr[i][j]]) return 0;
        }
    }
    return 1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        vector<int> arr[MAX_V + 1];
        int color[MAX_V + 1], visited[MAX_V + 1] = { 0 };

        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for (int i = 1; i <= v; i++) {
            if (!visited[i]) dfs(arr, color, visited, i, 0);
        }

        if (isBipartiteGraph(arr, color, v)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}