#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(2, vector<int> (n));
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i ++) {
        dp[0][i] = max(dp[0][i], dp[0][i - 1] + abs(a[i] - a[i - 1]));
        dp[0][i] = max(dp[0][i], dp[1][i - 1] + abs(a[i] - 1));
        dp[1][i] = max(dp[1][i], dp[0][i - 1] + abs(a[i - 1] - 1));
        dp[1][i] = max(dp[1][i], dp[1][i - 1] + 0);
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
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