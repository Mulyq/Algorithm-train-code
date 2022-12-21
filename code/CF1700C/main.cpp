#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    ll res = 0;
    ll ex = 0;
    for(int i = 0; i < n; i ++) {
        if(i != n - 1) {
            if(a[i] > a[i + 1]) {
                res += a[i] - a[i + 1];
            } else {
                res += a[i + 1] - a[i];
                ex += a[i + 1] - a[i];
            }
        }
    }
    cout << res + abs(ex - a[n - 1]) << '\n';
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