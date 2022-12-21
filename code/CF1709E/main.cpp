#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int n, res;
int a[MAXN], p[MAXN], fa[MAXN];
set<int> S[MAXN];
vector<int> e[MAXN];
namespace LCA {
    int fa[MAXN][20];
    int dep[MAXN];
    void dfs(int r, int f) {
        dep[r] = dep[f] + 1;
        fa[r][0] = f;
        for(auto v : e[r]) if(f != v) {
            dfs(v, r);
        }
    }
    void init(int r) {
        dfs(r, r);
        for(int i = 1; i <= 17; i ++) {
            for(int j = 1; j <= n; j ++) {
                fa[j][i] = fa[fa[j][i - 1]][i - 1];
            }
        }
    }
    int lca(int a, int b) {
        if(dep[a] < dep[b]) swap(a, b);
        int temp = dep[a] - dep[b];
        for(int i = 0; temp; i ++, temp >>= 1) {
            if(temp & 1) {
                a = fa[a][i];
            }
            i ++;
        }
        if(a == b) return a;
        for(int i = 17; i >= 0; i --) {
            if(fa[a][i] != fa[b][i]) {
                a = fa[a][i], b = fa[b][i];
            }
        }
        return fa[a][0];
    }
}
void dfs(int r, int f) {
    fa[r] = f;
    p[r] = p[f] ^ a[r];
    S[r].insert(p[r]);
    bool ok = 1;
    for(int v : e[r]) if(v != f) {
        dfs(v, r);
        if(S[v].size() > S[r].size()) swap(S[v], S[r]);
        for(auto x : S[v]) {
            if(S[r].find(x ^ a[LCA::lca(v, r)]) != S[r].end()) {
                ok = 0;
            }
        }
        for(auto x : S[v]) {
            S[r].insert(x);
        }
    }     
    if(!ok) {
        res ++;
        S[r].clear();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    LCA::init(1);
    dfs(1, 0);
    cout << res << '\n';
}