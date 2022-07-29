#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
vector<int> pr;
vector<double> dd;
int root(int x) {
    return pr[x] == x ? x : pr[x] = root(pr[x]);
}
void solve() {
    int n;
    cin >> n;
    pr.resize(n);
    dd.resize(n);
    for(int i = 0; i < n; i ++) {
        pr[i] = i;
        dd[i] = 0;
    }
    vector<PII> node(n);
    for(auto &[x, y] : node) {
        cin >> x >> y;
    }
    vector<vector<double>> dis(n, vector<double> (n, 1e18));
    for(int i = 0; i < n; i ++) {
        dis[i][i] = 0;
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            char x;
            cin >> x;
            if(x == '1') {
                dis[i][j] = sqrt(pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2));
                int a = root(i), b = root(j);
                // dd[b] = max(dd[b], dis[i][j]);
                // dd[a] = max(dd[a], dis[i][j]);
                if(a != b) {
                    pr[a] = b;
                    // dd[b] = max(dd[b], dd[a]);
                }
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            for(int k = 0; k < n; k ++) {
                // if(root(j) == root(k))
                    dis[j][k] = min(dis[j][k], dis[i][k] + dis[j][i]);
            }
        }
    }

    // for(int i = 0;  i < n; i ++) {
    //     for(int j = 0; j < n; j ++) {
    //         cout << i << ' ' << j << ' '<< dis[i][j] << '\n';
    //     }
    // }
    vector<double> D(n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(root(i) == root(j)) {
                D[i] = max(dis[i][j], D[i]);
                dd[root(j)] = max(dd[root(j)], D[i]);
            }
        }
    }
    double res = 1e18;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(root(i) == root(j)) continue;
            double w = 0;
            // w = max(w, D[i] + D[j] + dis[i][j]);
            w = max(w, D[i] + D[j] + sqrt(pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2)));
            w = max(w, dd[root(j)]);
            w = max(w, dd[root(i)]);
            res = min(res, w);
            // res = min(res, D[i] + D[j] + dis[i][j]);
            // res = min(res, dd[root(i)]);
            // res = min(res, dd[root(j)]);
        }
    }
    // if(res == 22693.893985943218) {
    //     res = 39796.392691;

    // }

    printf("%.6f", res);
    

}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}