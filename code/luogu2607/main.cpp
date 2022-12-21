#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e6 + 10, mod = 998244353;
int n;
vector<int> G[MAXN];
ll g[MAXN][2], f[MAXN][2], val[MAXN]; // 环dp, 树dp
bool vis[MAXN];
namespace Circle {
    vector<int> circle;
    int tag[MAXN];
    void init() {
        circle.clear();
        for(int i = 0; i < n; i ++) {
            tag[i] = -1;
        }
    }
    int dfs(int u, int p) {
        if(tag[u] != -1) {
            return u;
        }
        tag[u] = 1;
        for(auto v : G[u]) if(v != p) {
            int t = dfs(v, u);
            if(t > -1) {
                circle.push_back(u);
                tag[u] = 2;
                return t == u ? -1 : t;
            }
        }
        return -1;
    }
}
int du, dv; // 删边
// 树dp
ll dfs(int u, int p) {
    f[u][1] = val[u], f[u][0] = 0;
    for(int v : G[u]) if(v != p) {
        if((du == u && dv == v) || (du == v && dv == u)) continue;
        dfs(v, u);
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0], f[v][1]);
    }
    return max(f[u][1], f[u][0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> val[i];
        int x;
        cin >> x;
        x --;
        G[i].push_back(x);
        G[x].push_back(i);
    }
    ll res = 0;
    Circle::init();
    for(int i = 0; i < n; i ++) {
        if(Circle::tag[i] == -1) {
            du = dv = 0;
            Circle::circle.clear();
            Circle::dfs(i, i);
            ll add = 0;
            if(Circle::circle.size() <= 2) {
                dfs(Circle::circle[0], Circle::circle[0]);
                add = f[Circle::circle[0]][0];
                memset(f, 0, sizeof f);
                memset(vis, 0, sizeof vis);
                dfs(Circle::circle[1], Circle::circle[1]);
                add = max(add, f[Circle::circle[1]][0]);
            } else {
                du = Circle::circle[0], dv = Circle::circle[1];
                dfs(Circle::circle[0], Circle::circle[0]);
                add = f[Circle::circle[0]][0];
                memset(f, 0, sizeof f);
                memset(vis, 0, sizeof vis);
                dfs(Circle::circle[1], Circle::circle[1]);
                add = max(add, f[Circle::circle[1]][0]);
            }
            res += add;
        }
    }
    cout << res << '\n';
}