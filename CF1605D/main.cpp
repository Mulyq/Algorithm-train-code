#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 2e5 + 10;
int n;
vector<int> e[MAXN];
vector<int> col[2];
int color[MAXN];
void dfs(int r, int f) {
    if(color[f]) {
        color[r] = 0;
        col[1].push_back(r);
    } else {
        color[r] = 1;
        col[0].push_back(r);
    }
    for(auto v : e[r]) if(v != f) {
        dfs(v, r);
    }
}
int get(int x) {
    int res = 0;
    while(x) {
        x >>= 1;
        res ++;
    }
    return res - 1;
}
void solve() {
    cin >> n;
    col[0].clear();
    col[1].clear();
    for(int i = 0; i < n; i ++) {
        e[i].clear();
    }
    vector<int> p[30];
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, 0);
    int mm = 0;
    for(int i = 1; i <= n; i ++) {
        int x = get(i);
        mm = max(mm, x);
        p[x].push_back(i);
    }
    vector<int> res(n);
    for(int i = mm; i >= 0; i -- ) {
        int tt = 0;
        if(col[0].size() > col[1].size()) {
            tt = 0;
        } else {
            tt = 1;
        }
        for(auto x : p[i]) {
            res[col[tt].back()] = x;
            col[tt].pop_back();
        }
    }
    for(auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}