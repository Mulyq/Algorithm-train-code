#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 2e5 + 10;
vector<int> e[MAXN];
int dfs(int i, int p) {
    int res = 0, ex = 0;
    for(int v : e[i]) {
        if(v != p) {
            int x = dfs(v, i);
            res += x;
            if(x == 0) {
                ex += 1;
            }
        }
    }
    return res + max(0, ex - 1);
}
void solve() {
    int n;
    cin >> n;
    vector<int> deg(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int v, u;
        cin >> u >> v;
        e[u].push_back(v); 
        e[v].push_back(u); 
        deg[v] ++, deg[u] ++;
    }
    if(n == 1) {
        cout << "0\n";
        return ;
    }
    int res = n;
    int maxd = 1;
    for(int i = 1; i <= n; i ++) {
        if(deg[i] > deg[maxd]) {
            maxd = i;
        }
    }
    if(deg[maxd] >= 3) {
        res = min(res, dfs(maxd, maxd));
    } else {
        res = 1;
    }
    cout << res <<"\n";
    for(int i = 1; i <= n; i ++)
        e[i].clear();
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