#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e5 + 10, mod = 32768;
vector<int> a(mod);
vector<vector<int>> e(mod);
void bfs() {
    queue<PII> q;
    q.push({0, 0});
    vector<int> vis(mod);
    while(q.size()) {
        int x = q.front().first, d = q.front().second;
        q.pop();
        if(vis[x] == 1) {
            continue;
        }
        vis[x] = 1;
        a[x] = d;
        for(auto v : e[x]) {
            q.push({v, d + 1});
        }
    }
}
void solve() {
    for(int i = 1; i < mod; i ++) {
        e[(i + 1) % mod].push_back(i);
        e[(2 * i) % mod].push_back(i);
    }
    bfs();
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cout << a[x] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}