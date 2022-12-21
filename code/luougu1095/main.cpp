#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int m, s, t;
    cin >> m >> s >> t;
    vector<vector<ll>> dp(t + 1, vector<ll> (30));
    vector<vector<bool>> ok(t + 1, vector<bool> (30));
    int f = 0;
    int ss = 0, i = 0;
    for(; i < t; i ++) {
        if(m < 10) {
            dp[i][m] = ss;
            ok[i][m] = 1;
            break;
        }
        ss += 60, m -= 10;
        if(ss >= s) {
            cout << "Yes\n";
            cout << i + 1 << '\n';
            return ;
        }
    }
    f = i;
    if(t == i) {
        if(ss >= s) {
            cout << "Yes\n";
            cout << s / 60 << '\n';
        } else {
            cout << "No\n";
            cout << 60 * t << '\n';
        }
        return ;
    }
    for(; i < t; i ++) {
        for(int en = 0; en < 20; en ++) {
            if(ok[i][en]) {
                dp[i + 1][en + 4] = max(dp[i + 1][en + 4], dp[i][en]);
                ok[i + 1][en + 4] = 1;
                dp[i + 1][en] = max(dp[i + 1][en], dp[i][en] + 17);
                ok[i + 1][en] = 1;
                if(en >= 10) {
                    dp[i + 1][en - 10] = max(dp[i + 1][en - 10], dp[i][en] + 60);
                    ok[i + 1][en - 10] = 1;
                }
            }
        }
    }
    ll all = 0;
    for(int i = 0; i <= 10; i ++) {
        all = max(dp[t][i], all);
    }
    if(all >= s) {
        cout << "Yes\n";
        for(f; f <= t; f ++) {
            for(int i = 0; i <= 10; i ++) {
                if(dp[f][i] >= s) {
                    cout << f << '\n';
                    return ;
                }
            }
        }
    } else {
        cout << "No\n";
        cout << all << '\n';
    }
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