#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct Z {
    int val;
    int x, y;
    bool operator< (const Z &a) const {
        if(val != a.val) {
            return val < a.val;
        } else {
            return x < y;
        }
    }
};
void solve() {
    int n;
    cin >> n;
    ll res = 0;
    vector<vector<int>> p(n, vector<int> (n));
    vector<bool> over(n);
    vector<PII> op;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> p[i][j];
        }
    }
    priority_queue<Z> q;
    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            q.push({p[i][j], i, j});
        }
    }
    while(q.size()) {
        int v = q.top().val;
        int x = q.top().x;
        int y = q.top().y;
        q.pop();
        if(!over[x] && !over[y]) {
            op.push_back({x, y});
            res += v;
            over[y] = 1;
            for(int i = 0; i < n; i ++) {
                if(over[i] || i == x) continue;
                p[i][x] = p[x][i] = max(p[x][i], p[y][i]);
                q.push({p[x][i], min(x, i), max(x ,i)});
            }
        }
    }
    cout << res << '\n';
    for(auto &[x, y] : op) {
        cout << x + 1 << ' ' << y + 1 << '\n';
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
}