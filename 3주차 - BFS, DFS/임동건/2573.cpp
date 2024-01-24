#include <iostream>
#include <queue>

int N, M;
int height[300][300];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
bool visited[300][300];

void bfs(int x, int y) {
  std::queue<std::pair<int, int>> container;

  container.push({x, y});
  visited[y][x] = true;

  while (not container.empty()) {
    int cur_x = container.front().first;
    int cur_y = container.front().second;
    container.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur_x + dx[i];
      int ny = cur_y + dy[i];

      if (nx < 0 || nx >= M || ny < 0 || ny >= N)
        continue;
      if (height[cur_y][cur_x] == 0 || visited[ny][nx])
        continue;

      container.push({nx, ny});
      visited[ny][nx] = true;
    }
  }
}

void melt() {
  int decrease[300][300] = {0};
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (height[y][x] == 0)
        continue;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
          continue;
        if (height[ny][nx] == 0)
          decrease[y][x]++;
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      height[y][x] -= decrease[y][x];
      if (height[y][x] < 0)
        height[y][x] = 0;
    }
  }
}

int main() {
  std::cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++)
      std::cin >> height[y][x];
  }

  int result = 0;
  while (true) {
    std::fill(&visited[0][0], &visited[299][300], false);
    // 그래프 개수 구하기
    int iceberg_count = 0;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        if (not visited[y][x] && height[y][x] > 0) {
          bfs(x, y);
          iceberg_count++;
        }
      }
    }

    if (iceberg_count == 0) {
      result = 0;
      break;
    }
    if (iceberg_count > 1)
      break;

    melt();
    result++;
  }

  std::cout << result << '\n';

  return 0;
}