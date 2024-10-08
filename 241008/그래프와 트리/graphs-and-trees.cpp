#include <bits/stdc++.h>
using namespace std;

vector<int> edges[510];
vector<int> visited(510);

bool is_tree(int rt){
    queue<pair<int, int>> q;
    q.push({rt, rt});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(visited[cur.second]) return false;
        visited[cur.second] = true;

        for(auto a : edges[cur.second]){
            if(a != cur.first){
                q.push({cur.second, a});
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){ if(!visited[i + 1]) ans += is_tree(i + 1); };
    cout << ans;
    return 0;
}