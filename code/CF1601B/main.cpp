#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<bool> vis(n + 1);
    vector<int> pre(n + 1);
    int mm = n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    queue<int> q;
    q.push(n);
    while(q.size()) {
        int u = q.front();
        q.pop();
        int t = u;
        u += b[u];
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = mm - 1; i >= u - a[u]; i --) {
            q.push(i);
            pre[i] = t;
        }
        mm = min(mm, u - a[u]);
    }
    int res = 0, now = 0;
    vector<int> path;
    if(pre[now] == 0) {
        cout << -1 << '\n';
        return 0;
    }
    do {
        res ++;
        path.push_back(now);
        now = pre[now];
    } while(now != n);
    cout << res << '\n';
    reverse(path.begin(), path.end());
    for(int v : path) {
        cout << v << ' ';
    }
    cout << '\n';
}