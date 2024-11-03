#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int EMPTY = 0;

vector<int> edges[100010];
vector<int> dp(100010, EMPTY);
vector<int> sumn(100010, 0);

int caldp(int rt, int parent){
    if(dp[rt] != EMPTY) return dp[rt];
    dp[rt] = sumn[rt];
    for(auto i : edges[rt]){
        if(i == parent) continue;
        sumn[i] += sumn[rt];
        caldp(i, rt);
    }
    return 0;
}

signed main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int pr;
        cin >> pr;
        if(pr == -1) continue;
        edges[pr].push_back(i);
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        sumn[a] += b;
    }

    caldp(1, -1);

    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }
}