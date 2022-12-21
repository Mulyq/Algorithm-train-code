#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> dp(n + 1), pr(n + 1);
    int maxpr = 0;
    for(int i = 0; i < n; i ++) {
        if(i % 2 == 0 && maxpr <= i / 2) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
        }
        maxpr = max(maxpr, ++ pr[a[i]]);
    }

    for(int i = 0; i < n; i ++) {
        for(int i = 1; i <= n; i ++) {
            pr[i] = 0;
        }
        maxpr = 0;
        if(dp[i]) {
            for(int j = i + 1; j <= n; j ++) {
                if((j - i) % 2 && maxpr <= (j - i) / 2 && (j == n || a[j] == a[i])) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
                maxpr = max(maxpr, ++ pr[a[j]]);
            }
        }
    }
    cout << max(0, dp[n] - 1) << '\n';
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