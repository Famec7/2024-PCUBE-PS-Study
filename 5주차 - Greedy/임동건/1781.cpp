#include <iostream>
#include <queue>

// �ε����� �������, ���ҵ��� �Ŷ�� ����
std::vector<int> problems[200001];

void Solve() {
  int N{};
  std::cin >> N;

  int dead_line{}, cup_ramen_count{};
  for (int i = 0; i < N; i++) {
    std::cin >> dead_line >> cup_ramen_count;
    problems[dead_line].emplace_back(cup_ramen_count);
  }

  std::priority_queue<int, std::vector<int>> pq;
  int result{};
  for (int i = N; i > 0; i--) {
    for (auto &problem : problems[i])
      pq.emplace(problem);
    if (not pq.empty()) {
      result += pq.top();
      pq.pop();
    }
  }

  std::cout << result << '\n';
}

int main() {
  Solve();

  return 0;
}