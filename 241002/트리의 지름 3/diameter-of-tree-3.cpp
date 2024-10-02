#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edges[100010];

vector<pair<int, int>> farthest(int st, int n, int cnt){
    queue<int> q;
    vector<bool> visited(n + 1);
    vector<int> distance(n + 1);

    q.push(st);
    visited[st] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto a : edges[cur]){
            if(!visited[a.first]){
                visited[a.first] = true;
                distance[a.first] = distance[cur] + a.second;
                q.push(a.first);
            }
        }
    }

    priority_queue<pair<int, int>> pq;

    for(int i = 1; i <= n; i++){
        pq.push({distance[i], i});
    }

    vector<pair<int, int>> ans;

    while(cnt--){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
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

    set<pair<int, int>> pairs;

    priority_queue<int> pq;

    const int CNT = 5;

    auto tmp1 = farthest(1, n, CNT);
    for(auto a : tmp1){
        auto tmp2 = farthest(a.second, n, CNT);
        for(auto b : tmp2){
            if(pairs.find({a.second, b.second}) != pairs.end()) continue;
            pairs.insert({a.second, b.second});
            pairs.insert({b.second, a.second});
            pq.push(b.first);
        }
    }

    pq.pop();
    cout << pq.top();

    return 0;
}