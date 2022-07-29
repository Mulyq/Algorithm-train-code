#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int dp[300][300];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(dp, 0x3f, sizeof dp);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
    }
    for(int i = 0; i <= n; i ++) {
        dp[i][i] = 0;
    }
    for(int len = 1; len <= n; len ++) {
        for(int l = 1; l <= n; l ++) {
            int r = l + len;
            if(r > n) break;
            for(int x = l; x < r; x ++) {
                int t = ((a[r] - a[x]) * (x - l + 1) - (a[x] - a[l -1]) * (r - x) + (r - l)) / (r - l + 1);
                dp[l][r] = min(dp[l][x] + dp[x + 1][r] + max(0, t), dp[l][r]);
            }
        }
    }


    for(int len = 1; len <= n; len ++) {
        for(int l = 1; l <= n; l ++) {
            int r = l + len;
            if(r > n) break;
            cout << l << ' ' << r << '\n';
            cout << dp[l][r] << '\n';
        }
    }
    cout << '\n';
    cout << dp[1][n] << '\n';
}