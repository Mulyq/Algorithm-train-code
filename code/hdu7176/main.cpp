#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, k;
vector<PII> G[MAXN];
int dis[MAXN];
bool spfa(int s) {
    for(int i = 0; i <= n + 1; i ++) {
        dis[i] = -INF;
    }
    dis[s] = 0;
    queue<int> q;
    vector<bool> vis(n + 2);
    vector<int> cnt(n + 2);
    q.push(s);
    vis[s] = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(PII it : G[u]) {
            int v = it.first, w = it.second;
            if(dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n + 1) {
                    return 1;
                }
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return 0;
}
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        int p;
        cin >> p;
        G[max(i - k, 0)].push_back({min(i + k - 1, n),  p});
    }
    for(int i = 1; i <= n; i ++) {
        G[i - 1].push_back({i, 0});
    }
    // for(int i = 0; i <= n; i ++) {
    //     G[n + 1].push_back({i, 0});
    // }
    int q;
    cin >> q;
    for(int i = 0 ; i < q; i ++) {
        int l, r, b;
        cin >> l >> r >> b;
        G[r].push_back({l - 1, - b});
    }
    if(spfa(0)) {
        cout << - 1 << '\n';
    } else {
        cout << dis[n] << '\n';
    }
    for(int i = 0; i <= n; i ++) {
        G[i].clear();
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
}