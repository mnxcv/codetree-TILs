#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int EMPTY = 0;

inline int left_child(int node){ return node * 2; }
inline int right_child(int node){ return node * 2 + 1; }
inline int par(int node) {return node / 2;}

map<int, int> bintree;
vector<int> preorder(100010);

vector<pair<int, int>> child_nodes(200000);

void inord(int node){
    if(bintree[node] == EMPTY) return;
    inord(left_child(node));
    cout << bintree[node] << ' ';
    inord(right_child(node));
}

void pre(int node){
    if(bintree[node] == EMPTY) return;
    cout << bintree[node] << ' ';
    pre(left_child(node));
    pre(right_child(node));
}

void post(int node){
    if(bintree[node] == EMPTY) return;
    post(left_child(node));
    post(right_child(node));
    cout << bintree[node] << '\n';
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

void fill_bintree(int idx, int prest, int preed){
    //cerr << idx << ' ' << prest << ' ' << preed << '\n';
    if(prest == preed) { bintree[idx] = preorder[prest]; return; }

    int root = preorder[prest];
    bintree[idx] = root;

    int root_idx = prest;
    for(int i = prest; i <= preed; i++){
        if(preorder[i] < root){
            root_idx = i;
        }
    }

    if(root_idx != prest) fill_bintree(left_child(idx), prest + 1, root_idx);
    if(root_idx != preed) fill_bintree(right_child(idx), root_idx + 1, preed);

    return;
}

signed main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> preorder[i];

    fill_bintree(1, 1, n);

    // cerr << bintree[1];

    post(1); cout << '\n';
}