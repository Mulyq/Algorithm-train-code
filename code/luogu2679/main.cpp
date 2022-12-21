#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 4e7 + 10, mod = 1e9 + 7;
int dp[8][5][3];
void solve() {
    int n, m, ki;
    string s, t;
    cin >> n >> m >> ki >> s >> t;
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            for(int k = 0; k < ki; k ++) {
                if(s[i] == t[j]) {
                    dp[i + 1][j + 1][k + 1] += dp[i][j][k];
                    dp[i + 1][j + 1][k + 1] %= mod;
                    if(i + 1 < n && j + 1 < m  && s[i + 1] == t[j + 1]) {
                        dp[i + 2][j + 2][k + 1] += dp[i][j][k];
                        dp[i + 2][j + 2][k + 1] %= mod;
                    }
                }
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j][k] %= mod;
                dp[i][j + 1][k] += dp[i][j][k];
                dp[i][j + 1][k] %= mod;
            }
        }
    }
    cout << dp[n][m][ki] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}