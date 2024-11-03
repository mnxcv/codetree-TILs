#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int EMPTY = 0;

vector<int> edges[100010];
vector<int> dp(100010, EMPTY);

int caldp(int rt, int parent){
    if(dp[rt] != EMPTY) return dp[rt];
    int sum = 1;
    for(auto i : edges[rt]){
        if(i == parent) continue;
        int sub = caldp(i, rt);
        sum += sub;
    }
    return dp[rt] = sum;
}

signed main() {
    int n, r, q;
    cin >> n >> r >> q;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    caldp(r, -1);
    while(q--){
        int x;
        cin >> x;
        cout << dp[x] << endl;
    }
}