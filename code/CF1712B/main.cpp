#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    if(n & 1) {
        cout << 1 << ' ';
        for(int i = 2; i <= n; i += 2) {
            cout << i  + 1 << ' ' << i << ' ';
        }
    } else {
        for(int i = 1; i <= n; i += 2) {
            cout << i + 1 << ' ' << i << ' ';
        }
    }
    cout << '\n';
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