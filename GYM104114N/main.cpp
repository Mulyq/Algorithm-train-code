#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<bool> vis(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    priority_queue<PII> q;
    for(int i = 0; i < n; i ++) {
        q.push({a[i], i});
    }
    while(q.size()) {
        auto [v, pos] = q.top();
        q.pop();
        if(pos - 1 >= 0) {
            if(!vis[pos - 1]) {
                a[pos - 1] = max(a[pos - 1], v - m);
                q.push({a[pos - 1], pos - 1});
                vis[pos - 1] = 1;
            }
        }
        if(pos + 1 < n) {
            if(!vis[pos + 1]) {
                a[pos + 1] = max(a[pos + 1], v - m);
                q.push({a[pos + 1], pos + 1});
                vis[pos + 1] = 1;
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << a[i] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
}