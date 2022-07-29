#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n == 1) {
        if(m > 2) {
            cout << "-1\n";
            return ;
        }
    }
    if(m == 1) {
        if(n > 2) {
            cout << "-1\n";
            return ;
        }
    }
    int res = 0;
    res += 2 * (min(n ,m) - 1);
    int r = max(n, m);
    int l = min(n, m);
    if((r - l) % 2 == 1) {
        res += 1 + 4 * (int)((r - l) / 2);
    } else {
        res += 4 * (int)((r - l) / 2);
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