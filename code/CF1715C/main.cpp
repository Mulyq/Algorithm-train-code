#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    ll res = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<ll> b(n), c(n);
    b[0] = 1, c[0] = 1;
    int t = 0;
    for(int i = 1; i < n; i ++) {
        if(a[i] != a[i - 1]) b[i] = b[i - 1] + 1;
        else b[i] = b[i - 1];
    }
    for(int i = 1; i < n;  i++) {
        c[i] = c[i - 1] + b[i];
    }
    for(int i = 0; i < n; i ++) {
        if(!i) res += c[n - 1];
        else {
            if(b[i - 1] != b[i]) t = b[i - 1];
            res += c[n - 1] - c[i - 1] - (n - i) * t;
        }
    }
    // cout << res << '\n';
    while(m --) {
        int i, x;
        cin >> i >> x;
        i --;
        if(i - 1 >= 0 && a[i - 1] != a[i] && x == a[i - 1]) {
            res -= 1ll * i * (n - i);
        } else if(i - 1 >= 0 && a[i - 1] == a[i] && x != a[i - 1]) {
            res += 1ll * i * (n - i);
        }
        
        if(i + 1 < n && a[i + 1] != a[i] && x == a[i + 1]) {
            res -= 1ll * (i + 1) * (n - i - 1);
        } else if(i + 1 < n && a[i + 1] == a[i] && x != a[i + 1]) {
            res += 1ll * (i + 1) * (n - i - 1);
        }
        a[i] = x;
        cout << res << '\n';
    }
}