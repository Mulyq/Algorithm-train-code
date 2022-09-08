#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    if(m < n) {
        cout << "No\n";
        return ;
    }
    if(n & 1) {
        cout << "Yes\n";
        for(int i = 0; i < n - 1; i ++) {
            cout << 1 << ' ';
        }
        cout << m - n + 1 << '\n';
    } else {
        if(m & 1) {
            cout << "No\n";
            return ;
        }
        cout << "Yes\n";
        for(int i = 0; i < n - 2; i ++) {
            cout << 1 << ' ';
        }
        cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
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