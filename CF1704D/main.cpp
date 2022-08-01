#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll> (m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 1; j < m; j ++) {
            a[i][j] += a[i][j - 1];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 1; j < m; j ++) {
            a[i][j] += a[i][j - 1];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 1; j < m; j ++) {
            cout << a[i][j] << ' ' ;
        }
        cout << '\n';
    }
    for(int j = 0; j < m; j ++) {
        for(int i = 1; i < n; i ++) {
            a[i][j] -= a[0][j];
        }
    }
    cout << '\n';
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