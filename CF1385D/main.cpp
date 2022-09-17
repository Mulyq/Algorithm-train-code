#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, res;
string s;
int dfs(int l, int r, char x) {
    if(l == r) {
        return s[l] != x;
    }
    int m = l + r >> 1;
    int c1 = 0, c2 = 0;
    for(int i = l; i <= m; i ++) {
        if(s[i] != x) c1 ++;
    }
    for(int i = m + 1; i <= r; i ++) {
        if(s[i] != x) c2 ++;
    }
    return min(c1 + dfs(m + 1, r, x + 1), c2 + dfs(l, m, x + 1));
}
void solve() {
    cin >> n;
    res = n;
    cin >> s;
    s = '*' + s;
    cout << dfs(1, n, 'a') << '\n';
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