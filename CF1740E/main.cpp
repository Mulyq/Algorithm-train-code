#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n;
vector<vector<int>> G;
vector<int> dep;
vector<array<int, 2>> dp;
void dfs(int u) {
    dep[u] = 1;
    int t = 0;
    for(int v : G[u]) {
        dfs(v);
        t = max(t, dep[v]);
    }
    dep[u] += t;
    dp[u][0] = dep[u];
    for(int v : G[u]) {
        dp[u][1] += max(dp[v][0], dp[v][1]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    G.resize(n);
    dep.resize(n);
    dp.resize(n);;
    for(int i = 1; i < n; i ++) {
        int p ;
        cin >> p;
        p --;
        G[p].push_back(i);
    }
    dfs(0);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}