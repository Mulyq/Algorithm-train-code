#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    vector<bool> dp(26);
    int n = s.size(), res = 0;;
    for(int i = 0; i < n; i ++) {
        if(dp[s[i] - 'a']) {
            dp = vector<bool> (26, 0);
            res += 2;
        } else {
            dp[s[i] - 'a'] = 1;
        }
    }
    cout << n - res  << '\n';
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