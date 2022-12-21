#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void solve() {
    string s, t;
    cin >> s >> t;
    vector<set<int>> p(26);
    for(int i = 0; i < s.size(); i ++) {
        p[s[i] - 'a'].insert(i);
    }
    int pos = -1;
    int res = 1;
    for(int i = 0; i < t.size(); i ++) {
        auto x = p[t[i] - 'a'].upper_bound(pos);
        if(x == p[t[i] - 'a'].end()) {
            res ++;
            pos = *p[t[i] - 'a'].upper_bound(-1);
        } else {
            pos = *x;
        }
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
}