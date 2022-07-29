#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int x;
    cin >> x;
    if(x % 2 == 1) {
        if(x == 1) {
            cout << 3 << '\n';
        } else {
            cout << 1 << '\n';
        }
    } else {
        if((x & -x) != x) {
            cout << (x & -x) << '\n';
        } else {
            cout << (x & -x) + 1 << '\n';
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