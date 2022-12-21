#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<vector<int>> G;
vector<int> dp;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    vector<int> xl1(n), xl2(n);
    G.resize(n);
    dp.resize(n);
    iota(xl1.begin(), xl1.end(), 0);
    iota(xl2.begin(), xl2.end(), 0);
    sort(xl1.begin(), xl1.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    sort(xl2.begin(), xl2.end(), [&](int x, int y) {
        return b[x] < b[y];
    });
    dp[xl1[n - 1]] = 1;
    dp[xl2[n - 1]] = 1;
    for(int i = 0; i < n - 1; i ++) {
        G[xl1[i]].push_back(xl1[i + 1]);
        G[xl2[i]].push_back(xl2[i + 1]);
    }
    queue<int> q;
    q.push(xl1[n - 1]);
    q.push(xl2[n - 1]);
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : G[u]) if(!dp[v]) {
            dp[v] = 1;
            q.push(v);
        }
    }
    for(int i : dp) {
        cout << i;
    }
    cout << '\n';
    for(int i = 0; i < n; i ++) {
        G[i].clear();
    }
    dp.clear();
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