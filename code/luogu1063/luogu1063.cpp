#include<bits/stdc++.h>

using namespace std;
const int N = 220;
int a[N], dp[N][N], n;

int main () {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int l = 3; l <= n + 1; l ++) {
        for(int i = 1; i <= 2 * n - l + 1; i ++) {
            int j = i + l - 1;
            int all = -1e9;
            for(int x = i + 1; x <= j - 1; x ++) {
                // cout <<  i << ' ' << x << ' ' << dp[i][x] << '\n';
                // cout <<  x << ' ' << j << ' ' << dp[i][x] << '\n';
                // cout <<  x << ' ' << i << ' '  << j << ' '<< a[x] * a[i] * a[j] << '\n';
                all = max(all, dp[i][x] + dp[x][j] + a[x] * a[i] * a[j]);
                // cout << (i - 1) % n + 1 << " " << (j - 1) % n + 1 << ' ' << all << '\n';
                // cout << '\n';
            }
            dp[i][j] = all;
        }
        // cout << "\n";
    }
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        res = max(res, dp[i][i + n]);
    }
    cout << res << '\n';
}