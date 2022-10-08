#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int n, m, k;
struct Edge {
    int a, b, c;
};
ll dis[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++) {
        dis[i] = 1e18;
    }
    vector<Edge> G(m);
    for(auto &[a, b, c] : G) {
        cin >> a >> b >> c;
        a --, b --;
    }
    dis[0] = 0;
    for(int i = 0; i < k; i ++) {
        int e;
        cin >> e;
        e --;
        auto [a, b, c] = G[e];
        dis[b] = min(dis[b], dis[a] + c);
    }
    if(dis[n - 1] == 1e18) cout << -1 << '\n';
    else cout << dis[n - 1] << '\n';
}