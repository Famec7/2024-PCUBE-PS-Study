#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

//2923 숫자 게임

int N;
int A[101];
int B[101];
int A1[101];
int B1[101];

void input();
void cal();
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	input();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num_A, num_B;
		cin >> num_A >> num_B;
		A[num_A] ++;
		B[num_B] ++;
		cal();
	}
}
void cal() {
	int result = 0;
	int i = 1;
	int j = 99;
	for (int k = 1; k <= 99; k++)
		A1[k] = A[k], B1[k] = B[k];

	while (true) {
		//존재하는 수로 가기
		while (!A1[i] && i < 100) i++;
		while (!B1[j] && j > 0) j--;
		if (i > 99 || j < 1) break;

		result = max(i + j, result);


		int min_cnt = min(A1[i], B1[j]);
		A1[i] -= min_cnt;
		B1[j] -= min_cnt;

	}

	cout << result << '\n';
}

