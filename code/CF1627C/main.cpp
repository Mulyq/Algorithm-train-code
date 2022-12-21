#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
int n;
vector<vector<PII>> e;
vector<int> res;
vector<int> ban;
int w = 2;
void dfs(int v) {
    ban[v] = 1;
    for(auto it : e[v]) {
        if(!ban[it.first]) {
            res[it.second] = w;w = 5 - w;
            dfs(it.first);
            w = 3;
        }
    }
}
void solve() {
    cin >> n;
    w = 2;
    e.clear(),res.clear(),ban.clear();
    e.resize(n + 1);
    res.resize(n + 1);
    ban.resize(n + 1, 0);
    for(int i = 0; i < n - 1; i ++) {
        int v, u;
        cin >> v >> u;
        e[v].push_back({u, i});
        e[u].push_back({v, i});
    }
    for(int i = 1; i <= n; i ++) {
        if(e[i].size() >= 3) {
            cout << -1 << '\n';
            return;
        }
    }
    dfs(1);
    for(int i = 0; i < n - 1; i ++) {
        cout << res[i] << ' ' ;
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while( T --) {
        solve();
    }
    return 0;
}