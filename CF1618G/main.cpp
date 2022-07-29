#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
struct DSU {
    int N;
    vector<int> pr, rnk;
    DSU(int n) : N(n) {
        pr.resize(N);
        rnk.resize(N);
        for(int i = 0; i < N; i ++) {
            pr[i] = i;
            rnk[i] = 1;
        }
    }
    int root(int x) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
    }
    bool same(int a, int b) {
        return root(a) == root(b);
    }
    bool unite(int a, int b) {
        int A = root(a), B = root(b);
        if(A == B) return 0;
        if(rnk[A] == rnk[B]) rnk[A] ++;
        else if(rnk[A] > rnk[B]) swap(rnk[A], rnk[B]);
        pr[A] = B;
        return 1;
    }
};
void solve() {
    int n, m, q; ll sum = 0;
    cin >> n >> m >> q;
    vector<PII> a(n + m);
    vector<ll> b(n + m + 1);
    vector<int> siz(n + m);
    vector<PII> derta;
    for(int i = 0; i < n + m; i ++) {
        cin >> a[i].first;
        if(i < n) {
            a[i].second = 1;
            sum += a[i].first;
        }
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n + m; i ++) {
        if(i) derta.push_back({a[i].first - a[i - 1].first, i});
        siz[i] += a[i].second;
    }
    for(int i = 1;i < n + m + 1; i ++) {
        b[i] = b[i - 1] + a[i - 1].first;
    }
    vector<PII> query(q);
    vector<vector<int>> qa(q);
    vector<ll> res(q);
    for(int i = 0; i < q; i ++) {
        cin >> query[i].first;
        query[i].second = i;
    }
    sort(query.begin(), query.end());
    sort(derta.begin(), derta.end());
    for(int i = 0, j = 0; i < q && j < n + m - 1; i ++) {
        while(j < n + m - 1 && derta[j].first <= query[i].first) {
            qa[i].push_back(derta[j].second);
            j ++;
        }
    }
    DSU tree(n + m);
    for(int i = 0; i < q; i ++) {
        int k = query[i].first, lx = query[i].second;
        for(auto x : qa[i]) {
            if(tree.unite(x - 1, x)) {
                sum -= b[x] - b[x - siz[x - 1]];
                int tmp = tree.root(x);
                sum += b[tmp + 1 - siz[tmp]] - b[tmp + 1 - siz[tmp] - siz[x - 1]];
                siz[tmp] += siz[x - 1];
            }
        }
        res[lx] = sum;
    }
    for(int i = 0; i < q; i ++) {
        cout << res[i] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int T = 1;
    // cin >> T;
    while(T --) {
        solve();
    }
}