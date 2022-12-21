#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    if(k & 1) {
        cout << "YES\n";
        for(int i = 0; i < n; i += 2) {
            cout << i + 1 << ' ' << i + 2 << '\n';
        }
    } else {
        if(k / 2 % 2 == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(int i = 0; i < n; i += 2) {
                if((i/ 2) % 2 == 0) {
                    cout << i + 2 << ' ' << i + 1 << '\n';
                } else {
                    cout << i + 1 << ' ' << i + 2 << '\n';
                }
            }
        }
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