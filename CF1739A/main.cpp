#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            bool ok = 1;
            for(int k = 0; k < 8; k ++) {
                int x = i + dx[k], y = j + dy[k];
                if(x >= 1 && x <= n && y >= 1 && y <= m) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                cout << i << ' ' << j << '\n';
                return;
            }
        }
    }
    cout << 1 << ' ' << 1 << '\n';
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