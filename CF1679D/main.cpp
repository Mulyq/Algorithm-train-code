#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
vector<int> e[MAXN], re[MAXN];
int val[MAXN];
int n, m, res = -1;
ll k;
bool check(int m) {
    for(int i = 0; i < n; i ++) {
        re[i].clear();
    }
    vector<int> deg(n);
    for(int i = 0; i < n; i ++) {
        for(auto v : e[i]) {
            if(val[v] <= m && val[i] <= m) {
                re[i].push_back(v);
                deg[v] ++;
            }
        }
    }
    queue<int> q;
    vector<int> dp(n);
    for(int i = 0; i < n; i ++) {
        if(!deg[i] && val[i] <= m) q.push(i), dp[i] = 1;
    }
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto v : re[u]) {
            deg[v] --;
            dp[v] = max(dp[v], dp[u] + 1);
            if(!deg[v]) q.push(v);
        }
    }
    for(int i = 0; i < n; i ++) {
        if(val[i] <= m && (dp[i] >= k || deg[i])) {
            return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++) {
        cin >> val[i];
    }
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        e[u].push_back(v);
    }
    int l = 0, r = INF;
    while(r - l > 1) {
        int m = l + r >> 1;
        if(check(m)) r = m;
        else l = m;
    }
    if(r == INF) {
        cout << "-1 \n";
    } else {
        cout << r << '\n';
    }
}