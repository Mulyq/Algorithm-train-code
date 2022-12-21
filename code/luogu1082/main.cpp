#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int exgcd(int a, int b, int &x, int &y) {
    int d = a;
    if(b) {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1, y = 0;
    }
    return d;
}
void solve() {
    int a, b;
    cin >> a >> b;
    int x, y;
    exgcd(a, b, x, y);
    cout << (x + b) % b << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}