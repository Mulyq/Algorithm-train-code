#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    int mx = 0, my = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> a[i][j];
            if(a[i][j] > a[mx][my]) {
                mx = i, my = j;
            }
        }
    }
    int l = max(mx + 1, n - mx);
    int t = max(my + 1, m - my);
    cout << l * t << '\n';
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