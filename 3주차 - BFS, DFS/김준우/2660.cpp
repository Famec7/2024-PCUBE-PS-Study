#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int V;

bool isConnected[51][51] = { 0 };
bool visited[51] = { 0 };
int dist[51] = { 0 };
int score[51] = { 0 };


void inputEdges() {
    int v1, v2;

    cin >> v1 >> v2;
    while (v1 != -1) {
        isConnected[v1][v2] = true;
        isConnected[v2][v1] = true;
        cin >> v1 >> v2;
    }
}

int checkFriends(int v) {
    queue<int> bfs;
    bfs.push(v);
    dist[v] = 0;

    int cnt = 0;
    while (!bfs.empty()) {
        int now = bfs.front();
        bfs.pop();

        if (visited[now]) continue;
        visited[now] = true;

        for (int i = 1; i <= V; i++)
            if (!visited[i] && isConnected[now][i]) {
                bfs.push(i);
                dist[i] = min(dist[i], dist[now] + 1);
            }
    }
    int ans = 0;
    for (int i = 1; i <= V; i++)
        ans = max(ans, dist[i]);
    return ans;
}

int findMinDist() {
    int ans = 60;
    for (int i = 1; i <= V; i++)
        ans = min(ans, score[i]);
    return ans;
}

void printResult(int cutline) {
    int cnt = 0;

    cout << cutline << " ";

    for (int i = 1; i <= V; i++)
        if (score[i] == cutline)
            cnt++;

    cout << cnt << endl;

    for (int i = 1; i <= V; i++)
        if (score[i] == cutline)
            cout << i << " ";

}

int main() {

    cin >> V;
    inputEdges();
    for (int i = 1; i <= V; i++) {
        fill(visited, visited + V + 1, false);
        fill(dist, dist + V + 1, 60);
        score[i] = checkFriends(i);
    }

    int cutline = findMinDist();
    
    printResult(cutline);

    return 0;
}