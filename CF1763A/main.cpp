#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> c(20);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        for(int j = 0; j < 10; j ++) {
            if((x >> j) & 1) {
                c[j] ++;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 10; i ++) {
        if(c[i] != n && c[i] != 0) {
            res += (1 << i);
        }
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}