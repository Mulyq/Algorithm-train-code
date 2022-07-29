#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n, x, res = 0;
    cin >> n >> x;
    vector<int> a(n), b(n + 1), sum(n + 1, - INF);
    for(int i = 0; i < n ; i ++ ) {
        cin >> a[i];
        b[i + 1] = a[i];
    }
    for(int i = 1; i <= n; i ++ ) {
        b[i] += b[i - 1];
    }
    for(int i = 0; i <= n; i ++) {
        for(int j = 1; j <= n - i; j ++) {
            sum[i + 1] = max(sum[i + 1], b[i + j] - b[j - 1]);
        }
    }
    for(int i = 0; i <= n; i ++) {
        for(int j = i; j <= n; j ++) {
            res = max(res, sum[j] + x * i);
        }
        cout << res << ' ';
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