#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 3e5 + 10;
vector<int> tre[MAXN];
int ch[MAXN], dp[MAXN];
void dfs(int u, int f) {
    ch[f] ++;
    int all = 0;
    for(int v : tre[u]) if(v != f) {
        dfs(v, u);
        ch[u] += ch[v];
        all += dp[v];
    }
    for(int v : tre[u]) if(v != f) {
        dp[u] = max(dp[u], all - dp[v] + ch[v]);
    }
}
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        tre[a].push_back(b);
        tre[b].push_back(a);
    }
    dfs(1, 0);
    cout << dp[1] << '\n';
    for(int i = 0; i <= n; i ++) {
        tre[i].clear();
        dp[i] = 0;
        ch[i] = 0;
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