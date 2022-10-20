#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 5e3 + 10, mod = 998244353;
int n, m;
vector<int> G[MAXN];
vector<int> res, ste;
namespace Circle {
    vector<int> circle;
    int tag[MAXN];
    void init() {
        for(int i = 0; i < n; i ++) {
            tag[i] = -1;
        }
    }
    int dfs(int u, int f) {
        if(tag[u] != -1) {
            return u;
        }
        tag[u] = 1;
        for(auto v : G[u]) if(v != f) {
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
bool cmp(vector<int> &a, vector<int> &b) {
    if(!a.size()) {
        return 1;
    } else {
        for(int i = 0; i < n; i ++) {
            if(a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
    }
    return 0;
}
int du = -1, dv = -1; // 删的边
void dfs(int u, int p) {
    ste.push_back(u);
    for(int v : G[u]) if(v != p) {
        if((du == u && dv == v) || du == v && dv == u) continue;
        dfs(v, u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        G[u].push_back(v), G[v].push_back(u);
    }
    for(int i = 0; i < n; i ++) {
        sort(G[i].begin(), G[i].end());
    }
    if(m == n - 1) {
        dfs(0, 0);
        res = ste;
    } else {
        Circle::init();
        Circle::dfs(0, 0);
        for(int i = 0; i < Circle::circle.size() - 1; i ++) {
            du = Circle::circle[i], dv = Circle::circle[i + 1];
            ste.clear();
            dfs(0, 0);
            if(cmp(res, ste)) {
                res = ste;
            }
        }
    }
    for(int i : res) {
        cout << i + 1 << ' ';
    }
}