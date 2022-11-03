#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<int> p;
vector<int> a, b;
int n;
int res = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    p.resize(n), a.resize(n), b.resize(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i ++) {
        int fr;
        cin >> fr; fr --;
        p[i] = fr;
    }
    for(int i = 0 ; i < n; i ++) {
        if(b[p[i]] >= a[i] && p[i] != i) {
            cout << "-1\n";
            return 0;
        }
    }
    vector<bool> vis(n);
    vector<PII> res;
    for(int i = 0; i < n; i ++) {
        int u = i;
        vector<int> cir;
        while(!vis[u]) {
            cir.push_back(u);
            vis[u] = 1;
            u = p[u];
        }
        int ff = 0;
        for(int i = 0; i < cir.size(); i ++) {
            if(a[cir[i]] > a[cir[ff]]) {
                ff = i;
            }
        }
        for(int i = 1; i < cir.size(); i ++) {
            int x = cir[(ff + i) % cir.size()];
            res.push_back({cir[ff], x});
        }
    }
    cout << res.size() << '\n';
    for(auto &[x, y] : res) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
}