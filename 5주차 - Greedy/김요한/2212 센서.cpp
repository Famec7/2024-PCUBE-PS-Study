#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

//2212 ¼¾¼­

int N, K;
int result = 0;
vector<int> ss;
vector<int> dis;

void input();
void calDistance();
int main() {
	input();
	calDistance();
}

void input() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		ss.push_back(n);
	}
	sort(ss.begin(), ss.end());
}

void calDistance() {
	for (int i = 0; i < ss.size() - 1; i++) dis.push_back(ss[i + 1] - ss[i]);
	sort(dis.rbegin(), dis.rend());
	for (int i = K - 1; i < dis.size(); i++) result += dis[i];
	cout << result;
}

