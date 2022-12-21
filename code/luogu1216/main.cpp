#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n ;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) {
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= n; j ++) {
        dp[n][j] = a[n][j];
    }
    for(int i = n - 1; i >= 1; i --) {
        for(int j = 1; j <= i; j ++) {
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[1][1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}