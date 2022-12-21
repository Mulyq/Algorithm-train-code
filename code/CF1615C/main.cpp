#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] != '0') {
            c1 ++;
        }
        if(b[i] != '0') {
            c2 ++;
        }
    }
    if((c1 == 0 && c2 != 0) || (c1 != 0 && c2 == 0)) {
        cout << "-1\n";
        return ;
    }
    int res = INF;
    if(c1 == c2) {
        int t = 0;
        for(int i = 0; i < n; i ++) {
            if(a[i] == '1' && b[i] == '0') {
                t ++;
            }
        }
        res = min(res, 2 * t);
    }
    if(n - c1 + 1 == c2) {
        int t = 0;
        for(int i = 0; i < n; i ++) {
            if(!((a[i] - '0') ^ (b[i] - '0'))) {
                t ++;
            }
        }
        res = min(res, t);
    }
    if(res == INF) {
        cout << "-1\n";
        return;
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
    return 0;
}