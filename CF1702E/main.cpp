#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 10;
vector<int> e[MAXN];
int color[1000010];
int n;
bool dfs(int v, int c) {
    color[v] = c;
    for(auto u : e[v]) {
        if(color[u] == c) {
            return 0;
        } else if(color[u] == 0 && !dfs(u, -c)) {
            return 0;
        }
    }
    return 1;
}
bool check() {
    for(int i = 0; i < n; i ++) {
       	if(color[i] == 0) {
        	if(!dfs(i, 1)) {
               	return 0;
           	}
       	}
   	}
   	return 1;
}
void solve() {
    cin >> n;
    vector<vector<int>> tt (n);
    bool ok = 1;
    for(int i = 0; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        tt[u].push_back(i);
        tt[v].push_back(i);
        if(u == v) ok = 0;
    }
    for(int i = 0; i < n; i ++) {
        if(tt[i].size() != 2) ok = 0; 
    }
    if(!ok) {
        cout << "NO\n";
        return ;
    }
    for(int i = 0; i < n; i ++) {
        int u = tt[i][0], v = tt[i][1];
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(check()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    for(int i = 0; i < n; i ++) {
        e[i].clear();
        color[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}