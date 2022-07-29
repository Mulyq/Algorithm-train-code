#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
void solve() {
    int n;
    cin >> n;
    vector<PII> a(n / 2);
    for(int i = 0; i < n / 2; i ++) {
        char x, y;
        cin >> x >> y;
        a[i].first = x - '0', a[i].second = y - '0';
    }
    int res1 = 0, res2 = 0;
    int o = -1;
    for(int i = 0; i < n / 2; i ++) {
        if(a[i].second != a[i].first) {
            res1 ++;
        } else {
            if(o != a[i].first) {
                res2 ++;
                o = a[i].first;
            }
        }
    }
    res2 = max(res2, 1);
    cout << res1 << ' ' << res2 << '\n';
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