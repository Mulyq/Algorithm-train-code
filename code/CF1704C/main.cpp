#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> seg;
    for(int i = 0; i < m; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < m; i ++) {
        seg.push_back(a[i] - a[i - 1] - 1);
    }
    seg.push_back(n + a[0] - a[m - 1] - 1);
    sort(seg.rbegin(), seg.rend());
    int tim = 0;
    int res = 0;
    for(int x : seg) {
        if(x - tim == 1) {
            res ++;
        } else {
            res += max(0, x - tim - 1);
        }
        tim += 4;
    }
    cout << n - res << '\n';
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