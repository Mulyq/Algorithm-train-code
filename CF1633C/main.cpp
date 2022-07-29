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
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    ll hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    bool f = 0;
    for(ll i = 0; i <= k; i ++) {
        hc += a * i;
        dc += w * (k - i);
        ll tc = (hm + dc - 1) / dc;
        ll tm = (hc + dm - 1) / dm;
        if(tc <= tm) {
            f = 1;
            break;
        }
        hc -= a * i;
        dc -= w * (k - i);
    }
    cout <<(f ? "YES\n" : "NO\n");
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