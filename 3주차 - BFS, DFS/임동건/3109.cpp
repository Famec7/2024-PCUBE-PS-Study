#include <iostream>
#include <string>

int R, C;
bool pipe[10000][500];
int dy[3] = {-1, 0, 1};

bool solve(int x, int y) {
  if (x == C - 1)
    return true;

  for (int i = 0; i < 3; i++) {
    int nx = x + 1;
    int ny = y + dy[i];

    if (nx < 0 || nx >= C || ny < 0 || ny >= R)
      continue;
    if (pipe[ny][nx] == true)
      continue;

    pipe[ny][nx] = true;

    // pipe가 마지막 열에 설치가 되면 리턴
    bool ret = solve(nx, ny);
    if (ret)
      return true;
  }

  return false;
}

int main() {
  std::cin >> R >> C;

  std::string line;
  for (int y = 0; y < R; y++) {
    std::cin >> line;
    for (int x = 0; x < C; x++) {
      if (line[x] == 'x')
        pipe[y][x] = true;
    }
  }

  int result = 0;
  for (int y = 0; y < R; y++) {
    if (solve(0, y))
      result++;
  }

  std::cout << result << '\n';

  return 0;
}