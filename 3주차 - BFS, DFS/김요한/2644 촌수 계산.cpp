#include<iostream>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;



int N1, N2; //두 사람
int n; // 사람 수
int map[101][101];
int visit[101];
int chonsu = -1;


void printmap(int n) {
	cout << endl;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void findchon(int x, int cnt) {
	visit[x] = 1;

	if (map[x][N2] == 1) {
		chonsu = cnt;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (map[x][i] == 1 && visit[i] != 1) {		
			findchon(i, cnt+1);
		}
	}
}

int main() {
	int m,x,y;
	cin >> n;
	cin >> N1 >> N2;
	cin >> m;
	for (int i = 0; i < m;i++) {
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	//printmap(n);
	findchon(N1,1);
	cout << chonsu;

}



