#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
void solve() {
    ll res = 1;
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> row(n + 1), col(m + 1);
    vector<PII> op;
    while(q --) {
        int x, y;
        cin >> x >> y;
        op.push_back({x, y});
    }
    reverse(op.begin(), op.end());
    for(int i = 0; i < op.size(); i ++) {
        int x = op[i].first, y = op[i].second;
        if(!row[x] || !col[y]) {
            res *= k;
            row[x] = 1;
            col[y] = 1;
        }
    }
    cout << res % 998244353 << '\n';
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