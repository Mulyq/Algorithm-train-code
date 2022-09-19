#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<int> c(n);
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        cnt += (c[i] = abs(a[i] - b[i]));
    }
    if(cnt & 1) cout << "-1\n";
    else {
        if(y <= x) {
            if(cnt > 2 || cnt == 0) {
                cout << 1ll * cnt / 2 * y << '\n';
            } else {
                bool ok = 0;
                for(int i = 0; i < n - 1; i ++) {
                    if(c[i] == 1 && c[i + 1] == 1) {
                        ok = 1;
                        break;
                    }
                }
                if(!ok) cout << y << '\n';
                else cout << min(2ll * y, 1ll * x) << '\n';
            }
        } else {
            
        }
    }
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