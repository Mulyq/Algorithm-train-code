#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> a;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for(int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        a.pop();
        a.push(x);
    }
    ll res = 0;
    while(a.size()) {
        res += a.top();
        a.pop();
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