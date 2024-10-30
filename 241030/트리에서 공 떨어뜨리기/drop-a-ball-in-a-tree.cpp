#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int EMPTY = -1;

inline int left_child(int node){ return node * 2; }
inline int right_child(int node){ return node * 2 + 1; }
inline int par(int node) {return node / 2;}

map<int, char> bintree;

vector<pair<int, int>> child_nodes(200000);

void pre(int node){
    if(bintree[node] == EMPTY) return;
    pre(left_child(node));
    cout << bintree[node];
    pre(right_child(node));
}

void inord(int node){
    if(bintree[node] == EMPTY) return;
    cout << bintree[node];
    inord(left_child(node));
    inord(right_child(node));
}

void post(int node){
    if(bintree[node] == EMPTY) return;
    post(left_child(node));
    post(right_child(node));
    cout << bintree[node];
}

string to_binstr(int n){
    string ret;
    while(n){
        ret += (n % 2) + '0';
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    if(ret.empty()) ret = "0";
    return ret;
}

int binstr_to(string s){
    int ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret = ret * 2 + (s[i] - '0');
    }
    return ret;
}

void new_visit(int node, vector<bool>& visited){
    string binstr = to_binstr(node);
    //cerr << node << " to " << binstr << '\n';
    string tmpstr = "";
    for(int i = 0; i < binstr.size(); i++){
        tmpstr += binstr[i];
        int tmp = binstr_to(tmpstr);
        //cerr << tmp << ' ' << tmpstr << '\n';
        if(visited[tmp]) { cout << tmp << '\n'; return; }
    }
    visited[node] = true;
    cout << 0 << '\n';
}

signed main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        child_nodes[i] = {a, b};
    }

    int k;
    cin >> k;
    string kbin = to_binstr(k - 1);
    reverse(kbin.begin(), kbin.end());
    //cerr << kbin << '\n';
    
    int checking_bit = 0;

    int loc = 1;
    while(1){
        if(child_nodes[loc].first == EMPTY && child_nodes[loc].second == EMPTY) break;
        if(child_nodes[loc].first == EMPTY) loc = child_nodes[loc].second;
        else if(child_nodes[loc].second == EMPTY) loc = child_nodes[loc].first;
        else{
            if(checking_bit >= kbin.size() || kbin[checking_bit] == '0') loc = child_nodes[loc].first;
            else loc = child_nodes[loc].second;

            checking_bit++;
        }
    }

    cout << loc;
}