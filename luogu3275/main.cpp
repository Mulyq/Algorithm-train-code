#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
/*
1 a <= b, b <= a    add(b, a, 0), add(a, b, 0)
2 a + 1 <= b        add(a, b, 1)
3 b <= a            add(b, a, 0)
4 b + 1 <= a        add(b, a, 1)
5 a <= b            add(a, b, 0)
*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> e(n + 1);
    vector<int> dis(n + 1, 0);
    for(int i = 1; i <= n; i ++) {
        e[0].push_back({i, 1});
    }
    for(int i = 0; i < m; i ++) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) {
            e[a].push_back({b, 0});
            e[b].push_back({a, 0});
        } else if(op == 2) {
            if(a == b) {
                cout << -1 << '\n';
                return ;
            }
            e[a].push_back({b, 1});
        } else if(op == 3) {
            e[b].push_back({a, 0});
        } else if(op == 4) {
            if(a == b) {
                cout << -1 << '\n';
                return ;
            }
            e[b].push_back({a, 1});
        } else {
            e[a].push_back({b, 0});
        }
    }
    vector<int> vis(n + 1), cnt(n + 1);
    queue<int> q;
    for(int i = 0; i <= n; i ++) {
        q.push(i);
        vis[i] = 1;
    }
    while (q.size()) {
        int v = q.front();
        vis[v] = 0;
        q.pop();
        for(auto u : e[v]) {
            if(dis[u.first] < dis[v] + u.second) {
                dis[u.first] = dis[v] + u.second;
                cnt[u.first] = cnt[v] + 1;
                if(cnt[u.first] >= n + 1) {
                    cout << -1 << '\n';
                    return ;
                }
                if(!vis[u.first]) {
                    q.push(u.first);
                    vis[u.first] = 1;
                }
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; i ++) {
        res += dis[i];
    }
    cout << res << '\n';
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