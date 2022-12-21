#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int k, n;
    cin >> k >> n;
    vector<int> a(k + 1);
    a[1] = 1;
    for(int i = 2, d = 1; i <= k; i ++) {
        a[i] = a[i - 1] + 1;
        int r = n - a[i - 1] - d;
        if(r >= k - i) {
            a[i] = a[i - 1] + d;
            d ++;
        }
    }
    for(int i = 1; i <= k; i ++) {
        cout << a[i] << ' ';
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
}