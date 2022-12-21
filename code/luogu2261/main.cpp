#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll res = n * k;
    for(int l = 1, r = 1; l <= min(n, k); ) {
        r = min(k / (k / l), n);
        int v = k / l;
        res -= 1ll * (l + r) * (r - l + 1) / 2 * v;
        l = r + 1;
    }
    cout << res << '\n';
}