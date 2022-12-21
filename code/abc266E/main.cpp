#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<double> dp(n + 1);
    for(int i = n - 1; i >= 0; i --) {
        double sum = 0;
        for(int j = 1; j <= 6; j ++) {
            sum += max(1.0 * j, dp[i + 1]);
        }
        dp[i] = sum / 6.0;
    }
    cout << fixed << setprecision(10) << dp[0] << '\n';
}