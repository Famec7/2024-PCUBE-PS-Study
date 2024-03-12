#include <iostream>

void Solve() {
  int N{};
  std::cin >> N;

  int tab_count[1001]{0};
  int correct_tab_count[1001]{0};
  int diff[1001]{0};
  for (int i = 0; i < N; i++)
    std::cin >> tab_count[i];
  for (int i = 0; i < N; i++)
    std::cin >> correct_tab_count[i];

  // 차이를 구한다.
  for (int i = 0; i < N; i++)
    diff[i] = correct_tab_count[i] - tab_count[i];

  int dp[1001]{0};
  dp[0] = abs(diff[0]);
  for (int i = 1; i < N; i++) {
    // 이전과 부호가 다르면
    if (diff[i] * diff[i - 1] < 0)
      dp[i] = dp[i - 1] + abs(diff[i]);
    else {
      // 다음 줄이 최대가 아닌 경우도 있으니 따로 처리 Ex) 2 1 2
      if (abs(diff[i]) < abs(diff[i - 1]))
        dp[i] = dp[i - 1];
      // 다음 줄로 갈 수록 탭이 커지면 그대로 갱신
      else
        dp[i] = dp[i - 1] + abs(diff[i]) - abs(diff[i - 1]);
    }
  }

  std::cout << dp[N - 1] << '\n';
}

int main() {
  Solve();

  return 0;
}