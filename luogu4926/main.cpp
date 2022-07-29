#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
struct edge {
    int o, a, b, k;
};
vector<edge> op;
vector<PII> ops;
int n, s, t;
bool check(double T) {
    vector<vector<pair<int, double>>> e(n + 1);
    for(auto x : op) {
        if(x.o == 1) {
            if(x.k <= T) {
                return 0;
            } else {
                e[x.a].push_back({x.b, -log2(x.k - T)});
            }
        } else {
            e[x.a].push_back({x.b, log2(x.k + T)});
        }
    }
    for(auto x : ops) {
        e[0].push_back({x.first, log2(x.second)});
        e[x.first].push_back({0, -log2(x.second)});
    }
    vector<double> dis(n + 1);
    dis[0] = 0;
    vector<int> vis(n + 1, 1), cnt(n + 1, 0);
    queue<int> q;
    for(int i = 0; i <= n; i ++) {
        q.push(i);
    }
    while (q.size()) {
        int v = q.front();
        q.pop();
        vis[v] = 0;
        for(auto u : e[v]) {
            if(dis[u.first] > dis[v] + u.second) {
                dis[u.first] = dis[v] + u.second;
                cnt[u.first] = cnt[v] + 1;
                if(cnt[u.first] >= n + 2) {
                    return 1;
                }
                if(!vis[u.first]) {
                    vis[u.first] = 1;
                    q.push(u.first);
                }
            }
        }
    }
    return 0;
}
void solve() {
    cin >> n >> s >> t;
    for(int i = 0; i < s; i ++) {
        int o, a, b, k;
        cin >> o >> a >> b >> k;
        edge temp = {o, a, b, k};
        op.push_back(temp);
    }
    for(int i = 0; i < t; i ++) {
        int id, s;
        cin >> id >> s;
        PII temp = {id, s};
        ops.push_back(temp);
    }
    if(!check(0)) {
        cout << - 1 << '\n';
        return ;
    }
    double l = 0, r = 10, m;
    while(r - l > 1e-9) {
        m = (l + r) / 2.0;
        if(check(m)) l = m;
        else r = m;
    }
    cout << m << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}