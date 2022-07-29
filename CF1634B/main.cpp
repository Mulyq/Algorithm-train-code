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
    ll n, x, y;
    cin >> n >> x >> y;
    int a = x % 2, b = (a + 1) % 2;
    ll w = 0;
    for(int i = 0; i < n; i ++) {
        ll k;
        cin >> k;
        w = (w + k) % 2;
    }
    a = (w + a) % 2, b = (w + b) % 2;
    y %= 2ll;
    if(a == y) cout << "Alice\n";
    else cout << "Bob\n";
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