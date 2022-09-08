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
    int res = n;
    for(int i = 0; i < n * 2 - 1; i ++) {
        if(s[i] == ')' && s[i + 1] == '(') {
            res --;
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
    return 0;
}