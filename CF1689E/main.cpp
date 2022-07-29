#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int n;
struct DSU {
    int N;
    vector<int> pr;
    vector<int> rk;
    DSU (int n) : N(n) {
        pr.resize(N);
        rk.resize(N, 1);
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
        if(rk[X] == rk[Y]) rk[X] ++;
        if(rk[X] > rk[Y]) pr[Y] = X;
        else pr[X] = Y;
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
    if(check(a)) {
        cout << res << '\n';
        for(auto x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        for(int i = 0; i < n; i ++) {
            a[i] ++;
            if(check(a)) {
                cout << res + 1 << '\n';
                for(int x : a) {
                    cout << x << ' ';  
                }
                cout << '\n';
                return;
            }
            a[i] -= 2;
            if(check(a)) {
                cout << res + 1 << '\n';
                for(int x : a) {
                    cout << x << ' ';  
                }
                cout << '\n';
                return;
            }
            a[i] ++;
        }

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
            if((a[i] & (- a[i])) == low && i != xl) {
                a[i] ++;
                break;
            }
        }
        cout << res + 2 << '\n';
        for(int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
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