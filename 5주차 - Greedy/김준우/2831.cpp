#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N;

priority_queue<int, vector<int>, greater<>> pMen;
priority_queue<int> mMen;

priority_queue<int, vector<int>, greater<>> pWomen;
priority_queue<int> mWomen;

void inputData() {
    int tmp;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp > 0)
        pMen.push(tmp);
        else
            mMen.push(tmp);
    }

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp > 0)
            pWomen.push(tmp);
        else
            mWomen.push(tmp);
    }
}

int greedy() {
    int cnt = 0;

    while (!pMen.empty() && !mWomen.empty()) {
        int tmpMan = pMen.top();
        int tmpWoman = mWomen.top();

        if (tmpMan + tmpWoman < 0) {
            pMen.pop();
            mWomen.pop();
            cnt++;
        }
        else
            mWomen.pop();
    }

    while (!pWomen.empty() && !mMen.empty()) {
        int tmpWoman = pWomen.top();
        int tmpMan = mMen.top();

        if (tmpWoman + tmpMan < 0) {
            pWomen.pop();
            mMen.pop();
            cnt++;
        }
        else
            mMen.pop();
    }

    return cnt;
}

int main() {

    cin >> N;
    inputData();

    cout << greedy();

    return 0;
}