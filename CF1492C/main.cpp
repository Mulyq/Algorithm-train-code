#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
void solve() {
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> pos (26);
    for(int i = 0; i < n; i ++) {
        pos[s[i] - 'a'].push_back(i);
    }
    vector<int> be(m), en(m);
    for(int i = 0, j = 0; j < m; j ++, i ++) {
        while(s[i] != t[j]) i ++;
        be[j] = i;
    }
    for(int i = n - 1, j = m - 1; j >= 0; j --, i --) {
        while(s[i] != t[j]) i --;
        en[j] = i;
    }
    int res = 0;
    for(int i = 0; i < m - 1; i ++) {
        res = max(res, en[i + 1] - be[i]);
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}