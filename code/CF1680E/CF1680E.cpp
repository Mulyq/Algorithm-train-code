#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    string s[2];
    int n;
    cin >> n >> s[0] >> s[1];
    for(int i = 0; i < 2; i ++) {
        while(s[0].back() == '.' && s[1].back() == '.') {
            s[0].pop_back();
            s[1].pop_back();
        }
        reverse(s[1].begin(), s[1].end());
        reverse(s[0].begin(), s[0].end());
    }
    n = s[0].size();
    vector<vector<int>> c(2, vector<int> (n)), dp(2, vector<int> (n, INF));
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < n; j ++) {
            s[i][j] == '*' ? c[i][j] = 1 : c[i][j] = 0;
        }
    }
    dp[0][0] = c[1][0];
    dp[1][0] = c[0][0];
    for(int i = 1; i < n; i ++) {
        dp[0][i] = min(dp[0][i], dp[0][i - 1] + 1 + c[1][i]);
        dp[0][i] = min(dp[0][i], dp[1][i - 1] + 2);
        dp[1][i] = min(dp[1][i], dp[1][i - 1] + 1 + c[0][i]);
        dp[1][i] = min(dp[1][i], dp[0][i - 1] + 2);
    }
    cout << min(dp[0][n - 1] , dp[1][n - 1]) << '\n';
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