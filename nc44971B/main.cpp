#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> deg(n);
    vector<vector<pair<int, double>>> G(n);
    vector<double> all(n);
    for(int i = 0; i < n - 1; i ++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j ++) {
            int to;
            double p;
            cin >> to >> p;
            to --;
            G[i].push_back({to, p});
            all[i] += p;
            deg[to] ++;
        }
    }
    vector<double> dp(n);
    dp[0] = 1;
    queue<int> q;
    for(int i = 0; i < n; i ++) {
        if(! deg[i]) q.push(i);
    }
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto & [v, p] : G[u]) {
            dp[v] += dp[u] * p;
            if(! --deg[v]) {
                q.push(v);
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << fixed << setprecision(8) << dp[i] * (1 - all[i]) << ' ';
    }
    cout << '\n';
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