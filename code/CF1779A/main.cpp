#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = 0;
    for(int i = 1; i < n; i ++) {
        if(s[i] != s[0]) {
            ok = 1;
        }
    }
    if(!ok) {
        cout << "-1\n";
    } else {
        int res = 0;
        for(int i = 1; i < n; i ++) {
            if(s[i - 1] = 'L' && s[i] == 'R') {
                res = i;
                break;
            }
        }
        cout << res << '\n';
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
}