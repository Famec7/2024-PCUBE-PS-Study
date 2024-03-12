#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

//1461 µµ¼­°ü

int N;
int M;
int ans;
int maxDist = 0;
vector<int> L;
vector<int> R;

void input();
void cal(vector<int> vec);
int main() {
	input();
	cal(R);
	cal(L);
	cout << ans - maxDist;
}

void input() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		int dist;
		cin >> dist;
		if (dist > 0) R.push_back(dist);
		else L.push_back(dist*-1);
		
		if (maxDist < abs(dist))
			maxDist = abs(dist);
	}

	sort(R.begin(), R.end());
	sort(L.begin(), L.end());
}

void cal(vector<int> vec) {
	int cnt = vec.size();
	int pointer = vec.size()-1;
	while (pointer > -1) {
		ans += vec[pointer]*2;
		pointer -= M;
	}

}


