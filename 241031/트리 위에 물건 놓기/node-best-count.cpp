#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int EMPTY = 0;

inline int left_child(int node){ return node * 2; }
inline int right_child(int node){ return node * 2 + 1; }
inline int par(int node) {return node / 2;}

vector<int> edges[100010];
vector<int> dp_empty(100010, EMPTY);
vector<int> dp_fill(100010, EMPTY);

int caldp(int rt, int parent, bool fill = false){
    int sum = fill;
    for(auto i : edges[rt]){
        if(i == parent) continue;
        int filltmp = caldp(i, rt, true);
        int emptytmp = caldp(i, rt, false);
        if(fill){
            sum += min(filltmp, emptytmp);
        }else{
            sum += filltmp;
        }
    }
    return fill ? dp_fill[rt] = sum : dp_empty[rt] = sum;
}

signed main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    caldp(1, 1, true);
    caldp(1, 1, false);

    cout << min(dp_fill[1], dp_empty[1]) << endl;
}