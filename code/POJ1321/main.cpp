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
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
int n, k;
int res;
struct node {
    int x, y;
};

vector<node> g;
vector<int> px, py;
void dfs(int idx, int sum) {
    if(sum == 0) {res ++; return;}
    if(idx >= g.size()) return ;
    int x = g[idx].x, y = g[idx].y;
    if(px[x] == 1 || py[y] == 1) {dfs(idx + 1, sum); return;}
    else {
        px[x] = 1, py[y] = 1;
        dfs(idx + 1, sum - 1);
        px[x] = 0, py[y] = 0;
        dfs(idx + 1, sum);
    }
    return ;
}
void solve() {
    g.clear();
    px.clear(), py.clear();
    px.resize(n, 0), py.resize(n, 0);
    res = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            char s;
            cin >> s;
            if(s == '#') g.push_back({i, j});
        }
    }
    dfs(0, k);
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(cin >> n >> k) {
        if(n == -1 && k == -1) break; 
        solve();
    }
    return 0;
}