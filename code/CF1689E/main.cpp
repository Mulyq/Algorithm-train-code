#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int n;
struct DSU {
    int N;
    vector<int> pr;
    DSU (int n) : N(n) {
        pr.resize(N);
        for(int i = 0; i < N; i ++) {
            pr[i] = i;
        }
    }
    int root(int x) {
        return (x == pr[x]) ? x : pr[x] = root(pr[x]);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        pr[Y] = X;
        return 0;
    }
};
bool check(vector<int> a) {
    DSU dsu(n);
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            if(a[i] & a[j]) {
                if(!dsu.unite(i, j)) {
                    cnt ++;
                }
            }
        }
    }
    if(cnt == n - 1) return 1;
    return 0;
}
void solve() {
    cin >> n;
    int res = 0;
    vector<int> a(n);
    for(int i = 0 ;i < n; i ++) {
        cin >> a[i];
        if(!a[i]) a[i] ++, res ++;
    }
    bool ok = check(a);
    if(!ok) {
        for(int i = 0; i < n; i ++) {
            a[i] ++;
            ok |= check(a);
            if(ok) {
                res ++;
                break;
            }
            if(a[i] >= 3) {
                a[i] -= 2;
                ok |= check(a);
                if(ok) {
                    res ++;
                    break;
                }
                a[i] ++;
            } else {
                a[i] --;
            }
        }
        if(!ok) {
            res += 2;
            int xl = 0, low = 0;
            for(int i = 0; i < n; i ++) {
                int t = (a[i] & (-a[i]));
                if(t > low) {
                    low = t;
                    xl  = i;
                }
            }
            a[xl] --;
            for(int i = 0; i < n; i ++) {
                if((a[i] & (-a[i])) == low && i != xl) {
                    a[i] ++;
                    break;
                }
            }
        }
    }
    cout << res << '\n';
    for(int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
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