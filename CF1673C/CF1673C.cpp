#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10, mod = 1e9 + 7;
vector<int> hw;
bool oo(int x) {
    vector<int> a;
    while(x) {
        a.push_back(x % 10);
        x /= 10;
    }
    vector<int> b = a;
    reverse(b.begin(), b.end());
    for(int i = 0; i < a.size(); i ++) {
        if(a[i] != b[i]) return 0;
    }
    return 1;
}
int m;
int n;
vector<ll> dp(41000);
void solve() {
    cin >> m;
    cout << dp[m] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    for(int i = 1; i <= 4e4;i ++) {
        if(oo(i)) {
            hw.push_back(i);
        }
    }
    n = hw.size();
    dp[0] = 1;
    for(int j = 0; j < n; j ++) {
        for(int i = 1; i <= 40000; i ++) {
            if(i - hw[j] >= 0) {
                dp[i] = (dp[i] + dp[i - hw[j]]) % mod;
            }
        }
    }
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}