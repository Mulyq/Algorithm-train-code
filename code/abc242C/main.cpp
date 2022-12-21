#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10, mod = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> dp(11, vector<ll> (n + 1));
    for(int i = 1;i < 10; i ++) {
        dp[i][1] = 1;
    }
    for(int i = 2; i <= n; i ++) {
        for(int j = 1; j < 10; j ++) {
            dp[j][i] = (dp[j - 1][i - 1] + dp[j][i - 1] + dp[j + 1][i - 1]) % mod;
        }
    }
    ll res = 0;
    for(int i = 1; i < 10; i ++) {
        res = (res + dp[i][n]) % mod;
    }
    cout << res;
    return 0;
}