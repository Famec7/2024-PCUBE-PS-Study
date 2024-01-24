#include <iostream>
#include <queue>
#include <string>

int N, M;
int maze[100][100];
bool visited[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y) {
  std::queue<std::pair<int, int>> container;
  container.push({x, y});

  while (not container.empty()) {
    int cur_x = container.front().first;
    int cur_y = container.front().second;
    container.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cur_y + dy[i];
      int nx = cur_x + dx[i];

      if (nx < 0 || ny < 0 || nx >= M || ny >= N)
        continue;
      if (maze[ny][nx] == 1 && not visited[ny][nx]) {
        maze[ny][nx] = maze[cur_y][cur_x] + 1;
        container.push({nx, ny});
        visited[ny][nx] = true;
      }
    }
  }
}

int main() {
  std::cin >> N >> M;

  std::string line;
  for (int y = 0; y < N; y++) {
    std::cin >> line;
    for (int x = 0; x < M; x++)
      maze[y][x] = line[x] - '0';
  }

  bfs(0, 0);
  std::cout << maze[N - 1][M - 1] << '\n';

  return 0;
}