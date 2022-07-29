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
#include <bitset>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
vector<vector<PII>> g; 
vector<PII> res;
// vector<vector<int>> mem;
int n;
void dfs(int step, PII sum) {
    if(step == n) {
        res.push_back(sum);
        return ;    
    }
    for(auto it : g[step]) {
        sum.first += it.first, sum.second += it.second;
        dfs(step + 1,sum);
        sum.first -= it.first, sum.second -= it.second;
    }
}
void solve() {
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        while(k --) {
            int b, p;
            cin >> b >> p;
            g[i].push_back({b, p});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}