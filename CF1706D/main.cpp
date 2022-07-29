#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    vector<bool> vis(3001);
    int M = INF;
    for(int i = 0 ; i < n; i ++)  {
        cin >> a[i];
        M = min(M, a[i]);
        for(int j = 1; j <= k; j ++) {
            vis[a[i] / j] = 1;
        }
    }
    int res = INF;
    for(int i = 0; i <= M; i ++) {
        if(vis[i]) {
            int maxx = 0;
            for(int j = 0 ; j < n; j ++) {
                if(!i) {
                    maxx = max(maxx, a[j] / k);
                } else {
                    int x = a[j] / i;
                    if(!x) {
                        maxx = max(maxx, a[j]);
                    } else {
                        maxx = max(maxx, a[j] / min(x, k));
                    }
                }
            }
            res = min(res, maxx - i);
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