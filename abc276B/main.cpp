#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u  >> v;
        u -- , v --;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0; i < n; i ++) {
        sort(G[i].begin(), G[i].end());
    }
    for(int i = 0; i < n; i ++) {
        cout << G[i].size();
        for(int x : G[i]) {
            cout << " " << x + 1;
        }
        cout << '\n';
    }
}