#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

vector<pii> edges[10010];

pii farthest(int st, int n){
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
    int mx = -1, idx = -1;
    for(int i = 1; i<= n; i++){
        if(distance[i] > mx) { mx = distance[i]; idx = i;}
    }
    return {idx, mx};
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int st, ed, w;
        cin >> st >> ed >> w;
        edges[st].push_back({ed, w});
        edges[ed].push_back({st, w});
    }

    auto tmp = farthest(1, n);
    cout << farthest(tmp.first, n).second;
}