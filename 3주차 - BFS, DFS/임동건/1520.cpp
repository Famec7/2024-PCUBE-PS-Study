#include <functional>
#include <iostream>
#include <queue>

typedef struct _Point {
  int height;
  int x;
  int y;
} Point;

struct comp {
  bool operator()(Point &a, Point &b) { return a.height < b.height; }
};

int N, M;
int map[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solve(int x, int y) {
  int route[500][500] = {0};
  std::priority_queue<Point, std::vector<Point>, comp> container;
  container.push({map[y][x], x, y});
  route[y][x] = 1;

  while (not container.empty()) {
    int cur_x = container.top().x;
    int cur_y = container.top().y;
    container.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur_x + dx[i];
      int ny = cur_y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (map[ny][nx] < map[cur_y][cur_x]) {
        if (route[ny][nx] == 0)
          container.push({map[ny][nx], nx, ny});
        route[ny][nx] += route[cur_y][cur_x];
      }
    }
  }

  return route[M - 1][N - 1];
}

int main() {
  std::cin >> M >> N;

  for (int y = 0; y < M; y++) {
    for (int x = 0; x < N; x++)
      std::cin >> map[y][x];
  }

  int result = solve(0, 0);
  std::cout << result << '\n';

  return 0;
}