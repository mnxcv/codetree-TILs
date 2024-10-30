#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int EMPTY = 0;

inline int left_child(int node){ return node * 2; }
inline int right_child(int node){ return node * 2 + 1; }
inline int par(int node) {return node / 2;}

vector<int> edges[100010];
vector<int> node(100010, EMPTY);

int caldp(int n){
    if(edges[n].empty()) return node[n];
    int sum = node[n];
    for(auto i : edges[n]){
        sum += max(caldp(i), (int)0);
    }
    return node[n] = sum;
}

signed main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[c].push_back(i);
        node[i] = (2 * a - 1) * b;
    }
    
    caldp(1);

    cout << node[1] << '\n';
}