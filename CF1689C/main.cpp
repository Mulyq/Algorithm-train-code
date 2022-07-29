#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 3e5 + 10;
vector<int> tre[MAXN];
int ch[MAXN], dp[MAXN];
void dfs(int r, int f) {
    ch[f] ++;
    dp[r] = 0;
    int s = 0;
    for(auto x : tre[r]) if(x != f) {
        dfs(x, r);
        ch[f] += ch[x];
    }
    for(auto x : tre[r]) if(x != f) {
        dp[r] = max(dp[x], dp[r]);
    }

}
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        tre[u].push_back(v);
        tre[v].push_back(u);
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