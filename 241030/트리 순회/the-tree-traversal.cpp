#include <bits/stdc++.h>
using namespace std;
const int EMPTY = '.';

inline int left_child(int node){ return node * 2; }
inline int right_child(int node){ return node * 2 + 1; }
inline int par(int node) {return node / 2;}

map<int, char> bintree;

vector<pair<int, int>> child_nodes(100);

void pre(int node){
    if(bintree[node] == EMPTY) return;
    pre(left_child(node));
    cout << bintree[node];
    pre(right_child(node));
}

void inord(int node){
    if(bintree[node] == EMPTY) return;
    cout << bintree[node];
    inord(left_child(node));
    inord(right_child(node));
}

void post(int node){
    if(bintree[node] == EMPTY) return;
    post(left_child(node));
    post(right_child(node));
    cout << bintree[node];
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char a, b, c;
        cin >> a >> b >> c;
        child_nodes[a] = {b, c};
    }
    bintree[1] = 'A';

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int tmp = q.front(); q.pop();

        bintree[left_child(tmp)] = child_nodes[bintree[tmp]].first;
        if(bintree[left_child(tmp)] != EMPTY) q.push(left_child(tmp));
        bintree[right_child(tmp)] = child_nodes[bintree[tmp]].second;
        if(bintree[right_child(tmp)] != EMPTY) q.push(right_child(tmp));
    }

    inord(1); cout << '\n'; pre(1); cout << '\n';  post(1);

    return 0;
}