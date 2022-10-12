#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
ll msqrt(ll x) {
    ll l = 0, r = sqrt(x) + 10;
    while(l + 1 < r) {
        ll m = l + r >> 1;
        if(m * m <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
void solve() {
    ll l, r;
    cin >> l >> r;
    ll bl = msqrt(l), br = msqrt(r);
    ll res = 0;
    if(bl == br) {
        for(ll x = bl * bl; x < (bl + 1) * (bl + 1); x += bl) {
            if(x >= l && x <= r) res ++;
        }
    } else {
        res = (br - bl - 1) * 3;
        for(ll x = bl * bl; x < (bl + 1) * (bl + 1); x += bl) {
            if(x >= l && x <= r) res ++;
        }
        for(ll x = br * br; x < (br + 1) * (br + 1); x += br) {
            if(x >= l && x <= r) res ++;
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