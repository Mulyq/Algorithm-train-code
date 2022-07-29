#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, m, k;
    string a, b;
    cin >> n >> m >> k >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    string res;
    int l = 0, r = 0;
    for(int i = 0, j = 0; i < n && j < m;) {
        if((a[i] < b[j] && l < k) || r >= k) {
            res += a[i ++];
            r = 0, l ++;
        } else {
            res += b[j ++];
            l = 0, r ++;
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