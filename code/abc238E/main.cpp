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
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
struct DSU {
    int N;
    vector<int> p;
    vector<int> rnk;
    DSU(int n) {
        N = n;
        p.resize(N);
        rnk.resize(N + 1);
        for(int i = 0 ; i < N; i ++) {
            p[i] = i;
            rnk[i] = 1;
        }
    }
    int root (int x) {
        return p[x] == x ? x : p[x] = root(p[x]);
    }
    bool same(int a, int b) {
        return root(a) == root(b);
    }
    void unite(int a, int b) {
        int A = root(a), B = root(b);
        if(A == B) return;
        if(rnk[A] == rnk[B]) rnk[A] ++;
        else if(rnk[A] < rnk[B]) swap(rnk[A], rnk[B]);
        p[B] = A;
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    DSU tree(N + 1);
    while(Q --) {
        int l, r;
        cin >> l >> r;
        tree.unite(l - 1, r);
    }
    cout << (tree.same(N, 0) ? "Yes" : "No");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}