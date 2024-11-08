#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int EMPTY = -1;

vector<int> edges[100010];
vector<int> dp(100010, EMPTY);
vector<int> dp2(100010, EMPTY);
vector<int> par(100010, -1);

int ans = 0;

int caldp(int rt, int parent){
    par[rt] = parent;
    if(dp[rt] != EMPTY) return dp[rt];

    int mn = -1;

    for(auto i : edges[rt]){
        if(i == parent) continue;
        mn = max(mn, caldp(i, rt));
    }

    return dp[rt] = mn + 1;
}

int caldp2(int rt, int parent, int d){
    par[rt] = parent;
    if(dp2[rt] != EMPTY) return dp2[rt];

    int ans = 0;

    for(auto i : edges[rt]){
        if(i == parent) continue;
        if(dp[i] < d) continue;
        ans += (2 + caldp2(i, rt, d));
    }

    return dp2[rt] = ans;
}

signed main() {
    int n, r, d;
    cin >> n >> r >> d;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    caldp(r, -1);
    caldp2(r, -1, d);

    cout << dp2[r] << endl;
}