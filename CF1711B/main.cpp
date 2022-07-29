#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> yes(n);
    vector<int> sum(m);
    for(int i = 0; i < m; i ++) {
        int x, b;
        cin >> x >> b;
        x --, b --;
        yes[x] ++;
        yes[b] ++;
        sum[i] = a[x] + a[b];
    }
    if(m % 2 == 0) {
        cout << "0\n";
    } else {
        int minx = INF;
        int mina = INF;
        for(int i = 0; i < n; i ++) {
            if(yes[i] % 2 == 1) {
                minx = min(minx, a[i]);
            }
        }
        for(int i = 0; i < m; i ++) {
            mina = min(mina, sum[i]);
        }
        cout << min(minx, mina) << '\n';
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
    return 0;
}