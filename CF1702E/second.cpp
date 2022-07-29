#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 10;
vector<int> e[MAXN];
vector<int> vis(MAXN);
int n;
int dfs(int r, int p, int len) {
    vis[r] = 1;
    for(auto v : e[r]) if(v != p && !vis[v]) {
        return dfs(v, r, len + 1);
    }
    return len;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        e[i].clear();
        vis[i] = 0;
    }
    bool ok = 1;
    for(int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        if(a == b) ok = 0;
        a --, b --;
        e[a].push_back(b), e[b].push_back(a);
    }
    for(int i = 0; i < n; i ++) {
        if(e[i].size() != 2) {
            ok = 0;
            break;
        }
    }
    if(!ok) {
        cout << "NO\n";
        return ;
    }
    for(int i = 0; i < n; i ++) {
        if(!vis[i]) {
            int len = dfs(i, - 1, 0);
            if(len % 2 == 0) {
                cout << "NO\n";
                return ;
            }
        }
    }
    cout << "YES\n";
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