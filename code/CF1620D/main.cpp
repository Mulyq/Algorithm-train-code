#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> rec(10);
    int res = 0;
    bool ok = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    res = a[n - 1] / 3;
    if(a[n - 1] % 3 == 0) {
        for(int i = 0; i < n; i ++) {
            if(a[i] % 3) {
                res ++;
                break;
            }
        }
    } else {
        int k = a[n - 1] % 3;
        res ++;
        int t1 = 0, t2 = 0;
        for(int i = 0; i < n; i ++) {
            if(a[i] == a[n - 1]) continue;
            if(a[i] == 1) {
                t1 = 1;
            }
            if(a[i] == 2) {
                t2 = 1;
            }
        }
        if(a[n - 1] > 4)
            res += (t1 & t2);
        else
            res += t1 + t2;
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