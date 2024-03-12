#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

//2879 코딩은 예쁘게

int N;
int tab[1001];
int ans;
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) cin >> tab[i];

	for (int i = 0;i < N;i++) {
		int n;
		cin >> n;
		tab[i] -= n;
	}

	bool ok = true;

	while (ok) {
		ok = false;
		for (int i = 0; i < N;i++) {
			if (tab[i] == 0) continue;
			ok = true;
			int dist = tab[i];
			for (int j = i + 1; j <= N; j++) {
				if (tab[i] * tab[j] > 0) {
					dist = abs(tab[j]) < abs(dist) ? tab[j] : dist;
				}
				else {
					ans += abs(dist);
					for (int k = i; k < j; k++) tab[k] -= dist;
					i = j - 1;
					break;
				}
			}
		}
	}
	cout << ans;
}

