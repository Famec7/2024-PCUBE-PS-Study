#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N;
int ans;
int day = 1;

struct quiz {
    int deadline;
    int noodle;
};

struct cmp {
    bool operator()(quiz q1, quiz q2) {

        if (q1.deadline > q2.deadline)
            return true;
        else if (q1.deadline == q2.deadline 
            && q1.noodle < q2.noodle)
            return true;
        else
            return false;
    }
};

struct cmp2 {
    bool operator()(quiz q1, quiz q2) {

        if (q1.noodle > q2.noodle)
            return true;
        else
            return false;
    }
};

priority_queue<quiz, vector<quiz>, cmp> quizes;
priority_queue<quiz, vector<quiz>, cmp2> quiz_solved;

void inputData() {
    cin >> N;

    quiz tmp = { 0 };
 
    for (int i = 0; i < N; i++) {
        cin >> tmp.deadline >> tmp.noodle;
        quizes.push(tmp);
    }

}

void greedy() {
    while (!quizes.empty()) {
        quiz tmp = quizes.top();
        quizes.pop();

        if (day <= tmp.deadline) {
            quiz_solved.push(tmp);
            day++;
        }

        else if (quiz_solved.top().noodle < tmp.noodle) {
            quiz_solved.pop();
            quiz_solved.push(tmp);
        }

    }
}

void answer() {
    while (!quiz_solved.empty()) {
        ans += quiz_solved.top().noodle;
        quiz_solved.pop();
    }
}

int main() {

    inputData();
    greedy();
    answer();

    cout << ans;

    return 0;
}