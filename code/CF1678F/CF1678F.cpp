#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10, mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }
    ll res = 1;
    for(int i = 0; i < n; i ++) {
        if(i < n - k) {
            if(v[i] == -1) {
                res = (res * (k + i + 1)) % mod;
            } else if(v[i] == 0) {
                res = (res * (k + 1)) % mod;
            } else if(v[i] >= i + 1) {
                res = 0;
            }
        } else {
            if(v[i] == 0 || v[i] == - 1) {
                res = (res * ((k + i) % n + 1)) % mod; 
            } else {
                res = 0;
            }
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