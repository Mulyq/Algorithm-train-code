#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        e[x].push_back(i);
    }
    vector<int> res(n + 1);
    for(int i = 1; i <= n; i ++) {
        if(e[i].size()) {
            res[i] ++;
        }
        for(int j = 0; j + 1 < e[i].size(); j ++) {
            if((e[i][j] % 2) ^ (e[i][j + 1] % 2)) {
                res[i] ++;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
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