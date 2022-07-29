#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
struct DSU {
    int N;
    vector<int> pr, size;
    DSU(int n) : N(n) {
        pr.resize(N + 1);
        size.resize(N + 1);
        for(int i = 0; i <= N; i ++) {
            pr[i] = i;
            size[i] = 1;
        }
    }
    int root(int x) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        if(size[X] > size[Y]) {
            pr[Y] = X;
            size[X] += size[Y];
        } else {
            pr[X] = Y;
            size[Y] += size[X];
        }
    }
};
void solve() {
    int n;
    cin >> n;
    map<int,int> mp;
    DSU dsu(n);
    int idx = 0;
    for(int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        if(mp.find(a) == mp.end()) {
            mp[a] = idx ++;
        }
        if(mp.find(b) == mp.end()) {
            mp[b] = idx ++;
        }
        dsu.unite(mp[a], mp[b]);
    }
    int res = 0;
    for(int i = 0; i < n; i ++) {
        res = max(res, dsu.size[i]);
    }
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}