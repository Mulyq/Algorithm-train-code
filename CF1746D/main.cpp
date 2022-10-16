#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define int ll
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, k;
vector<int> G[MAXN];
int s[MAXN], c[MAXN];
ll a[MAXN], ma[MAXN];
void dfs(int u, int p) {
    a[u] = 1ll * s[u] * c[u];
    ma[u] = s[u];
    int ave = c[u] / max(1ll, (int)G[u].size() - 1);
    int ex = c[u] % max(1ll, (int)G[u].size() - 1);
    vector<int> temp;
    ll tt = 0;
    for(int v : G[u]) if(v != p) {
        // c[v] = ave;
        dfs(v, u);
        // a[u] += 1ll * s[v] * c[v];
        tt = max(tt, ma[v]);
        temp.push_back(v);
    }
    ma[u] = max(ma[u], tt);
    sort(temp.begin(), temp.end(), [&] (int x, int y){
        return ma[x] > ma[y];
    });
    for(int i = 0; i < ex; i ++) {
        c[temp[i]] = ave + 1;
        dfs(temp[i], u);
        a[u] += a[temp[i]];
    }
    for(int i = ex; i < temp.size(); i ++) {
        c[temp[i]] = ave;
        dfs(temp[i], u);
        a[u] += a[temp[i]];
    }
}
void solve() {
    cin >> n >> k;
    G[0].push_back(0);
    for(int i = 1; i < n; i ++) {
        int p;
        cin >> p;
        p --;
        G[p].push_back(i);
        G[i].push_back(p);
    }
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    c[0] = k;
    dfs(0, 0);
    // for(int i = 0; i < n; i ++) {
    //     cout << c[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < n; i ++) {
    //     cout << ma[i] << ' ';
    // }
    // cout << '\n';
    cout << a[0] << '\n';
    // ll res = 0;
    // for(int i = 0; i < n; i ++) {
    //     res += s[i] * c[i];
    // }
    // cout << res << '\n';
    for(int i = 0; i < n; i ++) {
        G[i].clear();
        c[i] = 0;
        s[i] = 0;
        ma[i] = 0;
        a[i] = 0;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}