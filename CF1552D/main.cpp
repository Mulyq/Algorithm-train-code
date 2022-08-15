#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
bool ok;
void dfs(vector<int> &a, int x, int c, int all) {
    if(x == a.size()) {
        if(c && ! all) {
            ok = 1;
        }
        return ;
    }
    dfs(a, x + 1, c + 1, all + a[x]);
    dfs(a, x + 1, c + 1, all - a[x]);
    dfs(a, x + 1, c, all);
}
void solve() {
    int n;
    ok = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    dfs(a, 0, 0, 0);
    cout << (ok ? "YES" : "NO") << '\n';
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