#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edges[50010];

vector<pair<int, int>> farthest_wless(int st, int n){
    queue<int> q;
    vector<int> distance(n + 1, 0);
    vector<bool> visited(n + 1, 0);
    q.push(st);
    visited[st] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto a: edges[cur]){
            if(!visited[a.first]){
                q.push(a.first);
                visited[a.first] = 1;
                distance[a.first] = distance[cur] + 1; // Set all w to 1
            }
        }
    }

    vector<pair<int, int>> ans;
    int mx = -1;
    for(int i = 1; i <= n; i++){
        if(distance[i] > mx) { 
            ans.clear(); ans.shrink_to_fit();
            mx = distance[i]; 
            ans.push_back({i, mx});
        }
        else if(distance[i] == mx){
            ans.push_back({i, mx});
        }
    }
    return ans;
}

int dist(int st, int ed, int n){
    queue<int> q;
    vector<int> distance(n + 1, 0);
    vector<bool> visited(n + 1, 0);
    q.push(st);
    visited[st] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto a: edges[cur]){
            if(!visited[a.first]){
                q.push(a.first);
                visited[a.first] = 1;
                distance[a.first] = distance[cur] + a.second;
            }
        }
    }
    return distance[ed];
}

int main() {
    int n, d;
    cin >> n >> d;
    for(int i = 1; i < n ; i++){
        int st, ed, w;
        cin >> st >> ed >> w;
        edges[st].push_back({ed, w});
        edges[ed].push_back({st, w});
    }

    int ans = 50010*1000;

    auto tmp = farthest_wless(1, n);
    for(auto a : tmp){
        auto tmp2 = farthest_wless(a.first, n);
        for(auto b : tmp2){
            ans = min(ans, ((dist(a.first, b.first, n) + (d - 1)) / d));
        }
    }
    cout << ans;
    return 0;
}