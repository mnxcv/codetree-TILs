#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edges[2010];
vector<int> dist(2010, -1);

pair<int, int> farthest(int st, int excl_st, int excl_ed, int n){
    for(int i = 0; i < n; i++){
        dist[i] = -1;
    }
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto a : edges[cur]){
            if((dist[a.first] == -1) &&
            (!(excl_st == cur && excl_ed == a.first)) && 
            (!(excl_ed == cur && excl_st == a.first))
            ){
                dist[a.first] = dist[cur] + a.second;
                q.push(a.first);
            }
        }
    }

    int ans = -1; int node = -1;

    for(int i = 0; i < n; i++){
        if(ans < dist[i]) {ans = dist[i]; node = i;}
    }
    return {ans, node};
}

int diameter(int start, int excl_st, int excl_ed, int n){
    auto tmp1 = farthest(start, excl_st, excl_ed, n);
    return farthest(tmp1.second, excl_st, excl_ed, n).first;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    int ans = -1;

    for(int i = 0; i < n; i++){
        for(auto a : edges[i]){
            ans = max(ans, diameter(i, a.first, i, n) + diameter(a.first, a.first, i, n) + a.second);
        }
    }

    cout << ans;

    return 0;
}