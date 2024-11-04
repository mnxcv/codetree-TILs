#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int EMPTY = 0;

vector<int> edges[100010];
vector<int> dp(100010, EMPTY);

int CN = -1;

int ans = 0;

int caldp(int rt, int parent){
    if(dp[rt] != EMPTY) return dp[rt];
    int sum = 1;
    int cnt = 0;
    for(auto i : edges[rt]){
        if(i == parent) continue;
        sum += caldp(i, rt);
    }

    if(CN == rt){
        int mx = -1;
        int mn = 2147483647;
        for(auto i : edges[rt]){
            if(i == parent) continue;
            mn = min(mn, caldp(i, rt));
            mx = max(mx, caldp(i, rt));
        }
        ans = mx - mn;
    }

    return dp[rt] = sum;
}

signed main() {
    int n, r;
    cin >> n >> r;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.push({r, -1});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(edges[cur.first].size() > 2 || (cur.second == -1 && edges[cur.first].size() > 1)){
            CN = cur.first;
            break;
        }
        for(auto i : edges[cur.first]){
            if(i == cur.second) continue;
            q.push({i, cur.first});
        }
    }

    caldp(r, -1);

    cout << ans << endl;
}