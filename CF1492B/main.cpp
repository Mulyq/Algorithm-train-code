#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), vis(n), pos(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = n; i >= 1; i --) {
        if(!vis[pos[i]]) {
            int p = pos[i];
            while(p < n && !vis[p]) {
                cout << a[p] << ' ';
                vis[p] = 1;
                p ++;
            }
        }
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