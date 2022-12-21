#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int Gcd(int x, int y) {
    return y ? Gcd(y, x % y) : x;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] < 0) a[i] = - a[i];
    }
    int gcd = a[0];
    for(int i = 1; i < n; i ++) {
        gcd = Gcd(gcd, a[i]);
    }
    cout << gcd << '\n';
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