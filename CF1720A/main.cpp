#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll A = 1ll * a * d, B = 1ll * b * c;
    if(A == B) {
        cout << "0\n";
    } else if(A == 0 || B == 0 || A % B == 0 || B % A == 0) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
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