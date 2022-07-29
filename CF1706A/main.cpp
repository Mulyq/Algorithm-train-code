#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    string res;
    for(int i = 0; i < m; i ++) {
        res.push_back('B');
    }
    for(int i = 0; i < n; i ++) {
        int l = a[i], r = m - a[i] + 1;
        l --, r --;
        if(l > r) swap(l, r);
        if(res[l] == 'A') {
            res[r] = 'A';
        } else {
            res[l] = 'A';
        }
    }
    cout << res << '\n';
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