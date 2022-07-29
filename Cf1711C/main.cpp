
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    bool res = 0;
    vector<int> a(k);
    vector<int> b(k);
    for(int i = 0; i < k; i ++) {
        cin >> a[i];
        b[i] = a[i] / m;
    }
        bool ok = 1;
    if(n % 2 == 1) {
        for(int i = 0; i < k; i ++) {
            if(a[i] % 2 == 1 && a[i] > 2) {
                n -= a[i];
                ok = 0;
                break;
            }
        }
        for(int i = 0; i < k; i ++) {
            if(a[i] > 3) {
                a[i] -= 3;
                n -= 3;
                ok = 0;
                break;
            }
        }
        if(ok) {
            res = 0;
        }
    }
    if(!ok) {
    for(int i = 0; i < k; i ++) {
        if(a[i] >= 2) {
            n -= (int)(a[i] / 2) * 2;
        }
    }
    if(n <= 0) {
        res |= 1;
    } else {
        res |= 0;
    }
    }
    swap(n, m);
    for(int i = 0; i < k; i ++) {
        b[i] = a[i] / m;
    }
    ok = 1;
    if(n % 2 == 1) {
        bool ok = 1;
        for(int i = 0; i < k; i ++) {
            if(a[i] % 2 == 1 && a[i] > 2) {
                n -= a[i];
                ok = 0;
                break;
            }
        }
        for(int i = 0; i < k; i ++) {
            if(a[i] > 3) {
                a[i] -= 3;
                n -= 3;
                ok = 0;
                break;
            }
        }
        if(ok) {
            res != 0;
        }
    }
    if(!ok) {
    for(int i = 0; i < k; i ++) {
        if(a[i] >= 2) {
            n -= (int)(a[i] / 2) * 2;
        }
    }
    if(n <= 0) {
        res |= 1;
    } else {
        res |= 0;
    }
    }
    if(res) cout <<"YES\n";
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}