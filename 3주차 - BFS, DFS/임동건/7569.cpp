#include <iostream>
#include <queue>
#include <string>

typedef struct _Dimension {
  int x;
  int y;
  int z;
} Dimension;

int N, M, H;
int farm[100][100][100];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
std::queue<Dimension> container;

void bfs() {
  while (not container.empty()) {
    int cur_x = container.front().x;
    int cur_y = container.front().y;
    int cur_z = container.front().z;
    container.pop();

    for (int i = 0; i < 6; i++) {
      int nx = cur_x + dx[i];
      int ny = cur_y + dy[i];
      int nz = cur_z + dz[i];

      if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H)
        continue;

      int &pos = farm[nz][ny][nx];
      if (pos == 0) {
        pos = farm[cur_z][cur_y][cur_x] + 1;
        container.push({nx, ny, nz});
      }
    }
  }
}

int main() {
  std::cin >> M >> N >> H;

  for (int z = 0; z < H; z++) {
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        std::cin >> farm[z][y][x];
        if (farm[z][y][x] == 1)
          container.push({x, y, z});
      }
    }
  }

  bfs();
  int result = 0;
  for (int z = 0; z < H; z++) {
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        if (farm[z][y][x] == 0) {
          std::cout << "-1\n";
          return 0;
        }

        result = std::max(result, farm[z][y][x]);
      }
    }
  }

  std::cout << result - 1 << '\n';

  return 0;
}