#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n;
vector<int> e, vis;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    e.resize(n); vis.resize(n, - 1);
    for(int i = 0; i < n; i ++) {
        int to;
        cin >> to; to --;
        e[i] = to;
    }
    ll res = 1;
    for(int i = 0; i < n; i ++) {
        int u = i;
        while(vis[u] == -1) {
            vis[u] = i;
            u = e[u];
        }
        if(vis[u] == i) res = (res << 1) % mod;
    }
    cout << res - 1 << '\n';
}