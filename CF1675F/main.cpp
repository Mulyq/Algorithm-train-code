#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, k, x, y;
ll res;
vector<int>  e[MAXN];
bool vis[MAXN];
vector<int> temp;
void dfs(int r, int fa) {
    temp.push_back(r);
    for(auto v : e[r]) if(v != fa) {
        dfs(v, r);
    }
    if(r == y) {
        for(auto v : temp) {
            vis[v] = 1;
        }
        res += temp.size() - 1;
    }
    temp.pop_back();
}
int val[MAXN];
bool flag[MAXN];
void dfs2(int r, int fa) {
    int mm = 0;
    for(auto v : e[r]) if(v != fa && !vis[v]) {
        dfs2(v, r);
        if(flag[v] || val[v]) {
            mm += (2 + val[v]);
        }
    }
    val[r] = mm;
}
void solve() {
    cin >> n >> k >> x >> y;
    x --, y --;
    for(int i = 0; i < n; i ++) {
        e[i].clear();
        vis[i] = 0;
        val[i] = 0;
        flag[i] = 0;
        res = 0;
    }
    vector<int> a(k);
    for(int i = 0; i < k; i ++) {
        cin >> a[i];
        a[i] --;
    }
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u -- , v -- ;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(x, x);
    for(int v : a) {
        // if(!vis[v]) {
            flag[v] = 1;
        // }
    }
    for(int i = 0; i < n; i ++ ) {
        if(vis[i]) {
            dfs2(i,i);
            res += val[i];
        }
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}