#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int EMPTY = 0;

inline int left_child(int node){ return node * 2; }
inline int right_child(int node){ return node * 2 + 1; }
inline int par(int node) {return node / 2;}

map<int, int> bintree;
vector<int> preorder(100010), inorder(100010);

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
    cout << bintree[node] << ' ';
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

void fill_bintree(int idx, int prest, int preed, int inst, int ined){
    // cerr << idx << ' ' << prest << ' ' << preed << '\n';
    if(prest == preed) bintree[idx] = preorder[prest];

    int root = preorder[prest];
    bintree[idx] = root;

    int root_idx = -1;
    for(int i = inst; i <= ined; i++){
        if(inorder[i] == root){
            root_idx = i;
            break;
        }
    }

    if(root_idx != inst) fill_bintree(left_child(idx), prest + 1, prest + (root_idx - inst), inst, root_idx - 1);
    if(root_idx != ined) fill_bintree(right_child(idx), prest + (root_idx - inst) + 1, preed, root_idx + 1, ined);

    return;
}

signed main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> preorder[i];
    for(int i = 1; i <= n; i++) cin >> inorder[i];

    fill_bintree(1, 1, n, 1, n);

    // cerr << bintree[1];

    post(1); cout << '\n';
}