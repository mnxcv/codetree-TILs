#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100010];
vector<int> indeg(100010);
vector<bool> visited(100010);

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        indeg[a]++; indeg[b]++;
    }

    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 1) q.push({i, 0});
    }

    int mx = -1;
    int dup = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(visited[cur.first]) continue;
        visited[cur.first] = true;
        if(mx == cur.second) dup = true;
        else {mx = cur.second; dup = 0;}
        for(auto a: edges[cur.first]){
            if(!visited[a]){
                if((--indeg[a]) == 1) q.push({a, cur.second + 1}); 
            }
        }
    }

    cout << mx + dup;

    return 0;
}