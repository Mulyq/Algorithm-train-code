#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, s, t;
    cin >> n >> q >> s >> t;
    vector<int> a(n + 2);
    for(int i = 0; i <= n; i ++) {
        cin >> a[i];
    }
    ll res = 0;
    for(int i = n; i > 0; i --) {
        a[i] -= a[i - 1];
    }
    for(int i = 1; i <= n; i ++) {
        if(a[i] > 0) {
            res -= a[i] * s;
        } else {
            res -= a[i] * t;
        }
    }
    while(q --) {
        int l, r, x;
        cin >> l >> r >> x;
        int temp = a[l];
        a[l] += x;
        if(temp > 0) {
            res += temp * s;
        } else {
            res += temp * t;
        }
        if(a[l] > 0) {
            res -= a[l] * s;
        } else {
            res -= a[l] * t;
        }
        if(r + 1 <= n) {
            temp = a[r + 1];
            a[r + 1] -= x;
            if(temp > 0) {
                res += temp * s;
            } else {
                res += temp * t;
            }
            if(a[r + 1] > 0) {
                res -= a[r + 1] * s;
            } else {
                res -= a[r + 1] * t;
            }
        }
        cout << res << '\n';
    }
}