#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int> ());
    vector<int> deg(n), in(n), out(n);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        G[a].push_back(b);
        out[a] ++, in[b] ++;
        deg[b] ++;
    }
    queue<int> q;
    int res = 0;
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i ++) {
        if(!deg[i]) {
            q.push(i);
        }
    }
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : G[u]) {
            if(out[u] > 1 && in[v] > 1) {
                dp[v] = max(dp[v], dp[u] + 1);
            }
            if(!-- deg[v]) {
                q.push(v);
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        res = max(res, dp[i]);
    }
    cout << res << '\n';
}