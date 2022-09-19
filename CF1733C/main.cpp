#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << "0\n";
        return;
    }
    vector<PII> res;
    res.push_back({1, n});
    for(int i = 1; i < n - 1; i ++) {
        if((a[i] + a[0]) % 2 == 1) {
            res.push_back({1, i + 1});
        } else {
            res.push_back({i + 1, n});
        }
    }
    cout << res.size() << '\n';
    for(auto [a, b] : res) {
        cout << a << ' ' << b << '\n';
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