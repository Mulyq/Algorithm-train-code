#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 4e5 + 10;
struct BIT {
    int N;
    vector<int> c;
    BIT() {
        N = MAXN;
        c.resize(N);
    }
    void add(int x, int p) {
        for(; x <= N; x += x & - x) {
            c[x] = max(c[x], p);
        }
    }
    int query(int x) {
        int res = 0;
        for(; x; x -= x & - x) {
            res = max(res, c[x]);
        }
        return res;
    }
} bit;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> pre, tt;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for(int i = 0; i < n; i ++) {
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }
    int res = INF;
    for(int i = 0; i < n; i ++) {
        if(i < k) {
            bit.add(a[i], i + 1);
        } else {
            int d = bit.query(a[i] - 1);
            if(d != 0) {
                res = min(res , i + 1 - d);
            }
        }
    }
    if(res == INF) res = - 1;
    cout << res << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}