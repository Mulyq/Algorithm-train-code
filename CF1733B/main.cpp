#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if((x > 0 && y > 0) || (x == 0 && y == 0)) {
        cout << "-1\n";
        return;
    }
    if(x < y) swap(x, y);
    if((n - 1) % x  != 0) {
        cout << "-1\n";
    } else {
        for(int i = 2; i <= n; i += x) {
            for(int j = 0; j < x; j ++) {
                cout << i << ' '; 
            }
        }
        cout << '\n';
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