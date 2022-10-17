#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int mp(char x) {
    int res = 0;
    if(x == 'a') res = 1;
    else if(x == 'e') res = 2;
    else if(x == 'h') res = 3;
    else if(x == 'n') res = 4;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s + s;
    vector<ll> dp(n);
    ll res = 0;
    for(int l = 1; l <= 16; l ++) {
        int r = l + n;
        vector<ll> dp (n + 1), d(20);
        for(int i = 1; i <= n; i ++) {
            for(int j = max(0, i - 15); j < i; j ++) {
                ll t = 0;
                for(int k = j + 1; k <= i; k ++) {
                    t = t * 31 + mp(s[l + k]);
                    t %= mod;
                }
                dp[i] = max(dp[i], dp[j] + t);
            }
        }
        res = max(res, dp[n]);
    }
    // cout << '\n';
    cout << res << '\n';
}