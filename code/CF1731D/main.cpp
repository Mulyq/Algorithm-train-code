#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
bool check(vector<vector<int>> &G, int x) {
    vector<vector<int>> cnt(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(G[i][j] >= x) {
                cnt[i][j] = 1;
            }
            cnt[i][j] = - cnt[i - 1][j - 1] + cnt[i][j - 1] + cnt[i - 1][j] + cnt[i][j];
        }
    }
    for(int i = 1; i + x - 1 <= n; i ++) {
        for(int j = 1; j + x - 1 <= m; j ++) {
            if(cnt[i + x - 1][j + x - 1] - cnt[i - 1][j + x - 1] - cnt[i + x - 1][j - 1] + cnt[i - 1][j - 1] == x * x) {
                return 1;
            }
        }
    }
    return 0;
}
void solve() {
    cin >> n >> m;
    vector<vector<int>> G(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> G[i][j];
        }
    }
    int l = 0, r = min(n, m) + 1;
    while(l + 1 < r) {
        int m = l + r >> 1;
        if(check(G, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
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