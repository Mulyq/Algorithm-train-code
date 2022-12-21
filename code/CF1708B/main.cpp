#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> res(n);
    for(int i = 0; i < n; i ++) {
        int x = i + 1;
        res[i] = (int)((l + (x - 1)) / x) * x;
        if(res[i] > r) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    for(int v :res ) {
        cout << v << ' ';
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