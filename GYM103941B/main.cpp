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
    s = s + s;
    vector<ll> d(16);
    for(int i = 0; i < 16; i ++) {
        if(!i) d[i] = 1;
        else d[i] = 31 * d[i - 1];
        d[i] %= mod;
    }
    ll res = 0;
    for(int l = 1; l <= 15; l ++) {
        int r = l + n;
        vector<ll> dp (n + 1);
        for(int i = 1; i <= n; i ++) {
            ll t = 0;
            for(int j = i, x = 0; j > max(0, i - 15); j --, x ++) {
                t += mp(s[l + j - 1]) * d[x];
                t %= mod;
                dp[i] = max(dp[i], dp[j - 1] + t);
            }
        }
        res = max(res, dp[n]);
    }
    cout << res << '\n';
}