#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int res = l1 + l2;
    if(l2 <= r1 && l2 >= l1) {
        res = min(res, l2);
    } else {
        if(r2 >= l1 && l2 <= l1) {
            res = min(res, l1);
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