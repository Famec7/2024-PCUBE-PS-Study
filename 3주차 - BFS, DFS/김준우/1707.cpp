#include <iostream>
#include <set>
#include <queue>
using namespace std;

int K;
int V, E;

queue<pair<int, int>> edges;
queue<pair<int, int>> keep;
set<int> setA;
set<int> setB;

bool findRightSet(int v1, int v2) {
    if (setA.find(v1) != setA.end()) {
        setB.insert(v2);
        return true;
    }
    if (setB.find(v1) != setB.end()) {
        setA.insert(v2);
        return true;
    }
    if (setA.find(v2) != setA.end()) {
        setB.insert(v1);
        return true;
    }
    if (setB.find(v2) != setB.end()) {
        setA.insert(v1);
        return true;
    }

    return false;
}

void inputEdges() {
    int v1, v2;

    for (int i = 0; i < E; i++) {
        cin >> v1 >> v2;
        edges.push(make_pair(v1, v2));
        keep.push(make_pair(v1, v2));
    }
}

void distribute() {
    int v1, v2;
    int cnt = keep.size();
    while (!keep.empty()) {

        v1 = keep.front().first;
        v2 = keep.front().second;
        keep.pop();

        if (cnt < 0) {
            setA.insert(v1);
            setB.insert(v2);
            cnt = keep.size();
        }
        else if (!findRightSet(v1, v2)) {
            keep.push(make_pair(v1, v2));
            cnt--;
        }
        else
            cnt = keep.size();
    }
}

bool checkBipartite() {
    while (!edges.empty()) {
        int v1, v2;
        v1 = edges.front().first;
        v2 = edges.front().second;
        edges.pop();

        if (setA.find(v1) != setA.end()
            && setA.find(v2) != setA.end())
            return false;
        if (setB.find(v1) != setB.end()
            && setB.find(v2) != setB.end())
            return false;        
    }
    return true;
}

int main() {

    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> V >> E;
        inputEdges();
        distribute();

        if (checkBipartite())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        edges = queue<pair<int, int>>();
        keep = queue<pair<int, int>>();
        setA.clear();
        setB.clear();
    }
    return 0;
}