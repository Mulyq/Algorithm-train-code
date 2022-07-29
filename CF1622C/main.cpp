#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

void solve() {
    int n;
    ll k, res = 9e18;
    cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1, 0);
    for(int i = 1;i <= n; i ++) 
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; i ++) 
        b[i] = b[i - 1] + a[i];
    for(ll i = 0; i < n; i ++) {
        ll w = k - b[n - i] + a[1];
        ll y = i, x;
        if(w < 0)
            x = a[1] - (w - i) / (i + 1);
        else
            x = a[1] - w / (i + 1);
        res = min(res, max(x, 0ll) + y);
    }
    res = max(res, 0ll);
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}