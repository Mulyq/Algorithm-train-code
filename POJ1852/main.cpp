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
// #include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int l, n;
    cin >> l >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++) cin >> a[i];
    int maxx = -INF, minx = -INF;
    for(int i = 0; i < n; i ++) {
        maxx = max(maxx, a[i] - 0);
        maxx = max(maxx, l - a[i]);
        minx = max(minx, min(a[i] - 0, l - a[i]));
    }
    cout << minx << ' ' << maxx << '\n';
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