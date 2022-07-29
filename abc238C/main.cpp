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
#include <stack>
#include <queue>
#include <bitset>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10, mod = 998244353;

void solve() {
    ll n;
    ll res = 0;
    cin >> n;
    if(n < 10) {
        res = (1 + n) * n / 2;
        cout << res ;
        return;
    }
    res += (1 + 9) * 9 / 2;
    ll x = 10;
    while(n >= x * 10) {
        res += ((9 * x + 1) % mod) * ((9 * x) % mod) / 2;
        x *= 10;
    }
    res += ((2 + n - x) % mod) * ((1 + n - x) % mod) / 2;
    cout << res % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}