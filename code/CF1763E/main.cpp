#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int p;
    cin >> p;
    if(p == 0) {
        cout << "0 0\n";
        return ;
    }
    vector<int> v, w;
    for(int i = 2; ; i ++) {
        int x = i * (i - 1) / 2;
        if(x > 2e5) break;
        w.push_back(x);
        v.push_back(i);
    }
    vector<int> dp(p + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < v.size(); i ++) {
        for(int j = w[i]; j <= p; j ++) {
            dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[p] << ' ';
    cout << dp[p] * (dp[p] - 1) / 2 - p << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
}