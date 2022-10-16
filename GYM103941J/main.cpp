#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n;
vector<int> v, siz, mi, pos;
vector<vector<int>> G;
void dfs(int u, int f) {
    siz[u] += 1;
    mi[u] = v[u];
    for(int i : G[u]) if(i != f) {
        dfs(i, u);
        siz[u] += siz[i];
        mi[u] = min(mi[u], mi[i]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    v.resize(n), siz.resize(n), mi.resize(n, INF), G.resize(n), pos.resize(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    for(int i = 1; i < n; i ++) {
        int f;
        cin >> f;
        f --;
        G[i].push_back(f);
        G[f].push_back(i);
    }
    dfs(pos[0], pos[0]);
    for(int i = 0; i <= n; i ++) {
        if(i == 0) {
            int res = 0;
            for(int i : G[pos[0]]) {
                res = max(res, siz[i]);
            }
            cout << res << ' ';
        } else if(i == n) {
            cout << n << ' ';
        } else {
            if(mi[pos[i]] < i) {
                cout << "0 ";
            } else {
                cout << n - siz[pos[i]] << ' ';
            }
        }
    }
}