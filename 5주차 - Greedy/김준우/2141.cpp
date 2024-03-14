#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<pair<long long, long long>> XA;
long long everyone;

void inputData() {
    long long tmp1, tmp2;
    for (int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        XA.emplace_back(tmp1, tmp2);
    }
    sort(XA.begin(), XA.end());
}

void countEveryone() {
    for (int i = 0; i < N; i++) {
        everyone += XA[i].second;
    }
}

int greedy() {
    long long cnt = 0;
    long long middle = (everyone + 1) / 2;
    
    int i = 0;
    while (cnt < middle) {
        cnt += XA[i].second;
        i++;
    }

    return XA[i - 1].first;
}

int main() {

    cin >> N;
    inputData();
    countEveryone();

    cout << greedy();

    return 0;
}