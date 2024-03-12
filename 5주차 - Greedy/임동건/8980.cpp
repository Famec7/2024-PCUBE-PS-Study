#include <algorithm>
#include <iostream>

typedef struct _Info {
  int from;
  int to;
  int box_count;
} Info;

bool cmp(const Info &a, const Info &b) {
  if (a.to == b.to)
    return a.from < b.from;

  return a.to < b.to;
}

int capacity[2001]{};
Info trucks[10000]{};

int main() {
  int N{}, C{};
  std::cin >> N >> C;

  int M{};
  std::cin >> M;

  for (int i = 0; i < M; i++) {
    std::cin >> trucks[i].from >> trucks[i].to >> trucks[i].box_count;
  }
  std::sort(std::begin(trucks), std::end(trucks), cmp);

  int result{};
  for (auto &truck : trucks) {
    int max_capacity{};
    for (int i = truck.from; i < truck.to; i++) {
      max_capacity = std::max(max_capacity, capacity[i]);
    }

    int &capacity_to_load = truck.box_count;
    if (capacity_to_load + max_capacity > C)
      capacity_to_load = C - max_capacity;

    for (int i = truck.from; i < truck.to; i++) {
      capacity[i] += capacity_to_load;
    }

    result += capacity_to_load;
  }

  std::cout << result << '\n';

  return 0;
}