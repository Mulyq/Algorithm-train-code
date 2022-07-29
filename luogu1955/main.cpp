#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e6 + 10, mod = 998244353;
int n;
vector<int> table;
struct T_T {
    int a, b;
    bool yes;
    bool operator< (const T_T & a) const {
        return yes > a.yes;
    }
};
struct DSU {
    int N;
    vector<int> pr;
    DSU (int n) : N(n) {
        pr.resize(N + 1);
        for(int i = 0; i <= N; i ++) {
            pr[i] = i;
        }
    }
    int root(int x) {
        return x == pr[x] ? x : pr[x] = root(pr[x]);
    }
    bool unite(int x, int y) {
        int X = root(x), Y =root(y);
        if(X == Y) return 1;
        pr[X] = Y;
        return 0;
    }
    bool check(int x, int y) {
        return root(x) == root(y);
    }
};
void solve() {
    table.clear();
    cin >> n;
    vector<T_T> ikun;
    for(int i = 0; i < n; i ++) {
        int a, b;
        bool c;
        cin >> a >> b >> c;
        table.push_back(a);
        table.push_back(b);
        ikun.push_back({a, b, c});
    }
    sort(table.begin(), table.end());
    table.resize(unique(table.begin(), table.end()) - table.begin());
    for(int i = 0; i < n; i ++) {
        ikun[i].a = lower_bound(table.begin(), table.end(), ikun[i].a) - table.begin();
        ikun[i].b = lower_bound(table.begin(), table.end(), ikun[i].b) - table.begin();
    }
    DSU dsu(table.size());
    sort(ikun.begin(), ikun.end());
    for(int i = 0; i < n; i ++) {
        if(ikun[i].yes) {
            dsu.unite(ikun[i].a, ikun[i].b);
        } else {
            if(dsu.check(ikun[i].a, ikun[i].b)) {
                cout << "NO\n";
                return ;
            }
        }
    }
    cout << "YES\n";
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