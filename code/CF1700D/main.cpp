#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0 ;i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i ++) {
        a[i] += a[i - 1];
    }
    ll mt = 0;
    for(int i = 0; i < n; i ++) {
        ll tt = (a[i] + i) / (i + 1);
        mt = max(mt, tt);
    }
    int q;
    cin >> q;
    while(q --) {
        ll t;
        cin >> t;
        if(t < mt) {
            cout << -1 << '\n';
            continue;
        }
        int l = 0, r = n + 1;
        while(r - l > 1) {
            int m = l + r >> 1;
            if(m * t >= a[n - 1]) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << '\n';
    }
    return 0;
}