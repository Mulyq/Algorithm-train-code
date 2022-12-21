#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, s, k;
    cin >> n >> s >> k;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        b[i] = a[i] + b[i - 1];
    }
    for(int i = 1, j = 1, kk = k; i <= n && j <= n; ) {
        bool ok = 0;
        int mx = 0;
        for(j = i; j < i + k && j <= n; j ++) {
            mx = max(mx - a[j], a[j]);
            if(mx <= s) {
                s += b[j] - b[i - 1];
                kk = k - (j - i);
                i = j + 1;
                ok = 1;
                break;
            }
        }
        if(!ok) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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