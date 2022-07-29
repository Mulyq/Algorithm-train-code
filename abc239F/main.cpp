#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
struct DSU {
    int N;
    vector<int> pr;
    vector<int> rnk;
    DSU(int n) : N(n) {
        pr.resize(N + 1);
        rnk.resize(N + 1);
        for(int i = 0 ; i <= N; i ++) {
            pr[i] = i;
            rnk[i] = 1;
        }
    }
    int root (int x) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
    }
    bool same(int a, int b) {
        return root(a) == root(b);
    }
    bool unite(int a, int b) {
        int A = root(a), B = root(b);
        if(A == B) return 1;
        if(rnk[A] < rnk[B]) {
            pr[A] = B;
        } else {
            if(rnk[A] == rnk[B]) {
                rnk[A] ++;
            }
            pr[B] = A;
        }
        return 0;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    vector<int> d(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> d[i];
    }
    while(m --) {
        int a, b;
        cin >> a >> b;
        d[a] --;
        d[b] --;
        if(d[a] < 0 || d[b] < 0 || dsu.unite(a, b)) {
            cout << -1 << '\n';
            return ;
        }
    }
    vector<vector<int>> temp(n + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < d[i]; j ++) {
            temp[dsu.root(i)].push_back(i);
        }
    }
    vector<int> c1;
    vector<vector<int>> c2;
    for(int i = 1; i <= n; i ++) {
        if(temp[i].size() == 1) {
            c1.push_back(temp[i].back());
        } else {
            c2.push_back(temp[i]);
        }
    }
    vector<PII> res;
    for(auto x : c2) {
        for(int i = 0; i < (int)x.size() - 1; i ++) {
            if(c1.empty()) {
                cout << - 1;
                return ;
            } else {
                dsu.unite(c1.back(), x[i]);
                res.push_back({c1.back(), x[i]});
                c1.pop_back();
            }
        }
        if(x.size()) {
            c1.push_back(x.back());
        }
    }
    if(c1.size() == 2) {
        if(dsu.unite(c1[0], c1[1])) {
            cout << - 1;
            return;
        } else {
            res.push_back({c1[0], c1[1]});
        }
        bool ok = 1;
        for(int i = 1; i < n; i ++) {
            if(dsu.root(i) != dsu.root(i + 1)) {
                ok = 0;
            }
        }
        if(ok) {
            for(auto it : res) {
                cout << it.first << ' ' << it.second << '\n';
            }
        } else {
            cout << - 1;
            return ;
        }
    } else {
        cout << - 1 << '\n';
        return ;
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
    return 0;
}