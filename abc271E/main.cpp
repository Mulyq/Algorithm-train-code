#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int n, m, k;
struct Edge {
    int u, v, val, xl;
};

vector<Edge> G[MAXN];
vector<int> rG[MAXN];
vector<int> E;
ll res = 1e18;
vector<bool> vis;
vector<int> path;
bool posib[MAXN];
void init(int n) {
    queue<int> q;
    q.push(n);
    posib[n] = 1;
    while(q.size()) {
        int x = q.front();
        q.pop();
        for(int y : rG[x]) if(!posib[y]) {
            posib[y] = 1;
            q.push(y);
        }
    }
}
bool check() {
    for(int i = 0, j = 0; i < E.size(); i ++) {
        if(path[j] == E[i]) j ++;
        if(j >= path.size()) return 1;
    }
    return 0;
}
void dfs(int x, ll sum) {
    if(sum >= res || !posib[x]) return;
    if(x == n) {
        if(check()) {
            res = min(res, sum);
        }
        return;
    }
    vis[x] = 1;
    for(auto &[u, v, val, xl] : G[x]) if(!vis[v]) {
        path.push_back(xl);
        dfs(v, sum + val);
        path.pop_back();
    }
    vis[x] = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    E.resize(k);
    vis.resize(n + 1, 0);
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({a, b, c, i});
        rG[b].push_back(a);
    }
    init(n);
    for(int i = 0; i < k; i ++) {
        int x;
        cin >> x;
        E[i] = x - 1;
    }
    dfs(1, 0);
    if(res == 1e18) {
        cout << "-1\n";
    } else {
        cout << res << '\n';
    }
}