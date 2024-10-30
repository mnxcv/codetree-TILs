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
    int k;
    cin >> k;
    vector<int> nodes((1 << k) + 1);
    for(int i = 1; i <= (1 << k) - 1; i++){
        cin >> nodes[i];
    }

    queue<pair<int, int>> q;
    
    int next_depth = 1;

    int tmp = 0;

    q.push({1, (1 << k) - 1});
    while(!q.empty()){
        auto [st, ed] = q.front(); q.pop();
        int sz = ed - st + 1;
        if(sz == 1){
            cout << nodes[st] << " ";
            continue;
        }
        int mid = st + sz / 2;
        cout << nodes[mid] << " ";
        if(++tmp == next_depth){
            next_depth *= 2;
            tmp = 0;
            cout << "\n";
        }
        q.push({st, mid - 1});
        q.push({mid + 1, ed});
    }

}