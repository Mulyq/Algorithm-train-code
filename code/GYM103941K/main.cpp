#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e1 + 10, mod = 998244353;
int n, q;
vector<int> G[MAXN], circle, tab;
int tag[MAXN], dis[MAXN], dp[400][MAXN];
bool vis[MAXN];
void init() {
    for(int i = 0; i < n; i ++) {
        tag[i] = -1;
    }
}
int dfs(int u, int p, int f) {
    vis[u] = 1;
    if(tag[u] != -1) {
        return u;
    }
    tag[u] = 1;
    for(auto v : G[u]) if(v != f) {
        int t = dfs(v, p, u);
        if(t > -1) {
            circle.push_back(u);
            tag[u] = p;
            return t == u ? -1 : t;
        }
    }
    return -1;
}
void work(int u, int x, int d, int f) {
    dp[x][d] ++;
    for(int v : G[u]) if(tag[v] < 2 && v != f) {
        work(v, u, x, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x; x --;
        G[i].push_back(x);
        G[x].push_back(i);
    }
    init();
    int xl = 0;
    for(int i = 0; i < n; i ++) {
        if(tag[i] == -1) {
            circle.clear();
            dfs(i, xl + 2, i);
            tab.push_back(circle.size());
            xl ++;
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << tag[i] << ' ';
    }
    cout << '\n';
    vector<int> rnk = tab;
    sort(rnk.begin(), rnk.end());
    rnk.resize(unique(rnk.begin(), rnk.end()) - rnk.begin());
    for(int i = 0; i < n; i ++) {
        int sz = tab[tag[i] - 2];
        int xl = lower_bound(rnk.begin(), rnk.end(), sz) - rnk.begin();
        work(i, xl, 0, i);
    }
    for(int i = 0; i < rnk.size(); i ++) {
        for(int j = 0; j < MAXN; j ++) {
            dp[i][j] += dp[i][j - 1];
        }
    }
    int q;
    cin >> q;
    while(q --) {
        ll a, b;
        cin >> a >> b;
        if(a == b) {
            cout << n << ' ';
        } else {
            ll c = abs(a - b);
            int add = c;
            ll mi = min(a, b);
            int res = 0;
            while(1) {
                if(c > rnk.back()) break;
                int xl = lower_bound(rnk.begin(), rnk.end(), c) - rnk.begin();
                if(rnk[xl] != c) {
                    c += add;
                    continue;
                }
                res += dp[xl][n] - dp[xl][mi - 1];
                c += add;
            }
            cout << res << ' ';
        }
    }
}