#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define int ll
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int n;
vector<int> c;
struct segtree {
    int N;
    vector<ll> p, v;
    void build(int k, int l, int r) {
        if(l == r) {
            p[k] = c[l];
            return ;
        }
        int m = l + r >> 1;
        build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
        p[k] = p[k << 1] + p[k << 1 | 1];
    }
    segtree(vector<int> &a) {
        N = a.size();
        N <<= 2;
        p = vector<ll> (N);
        v = vector<ll> (N);
        build(1, 1, n);
    }
    void add(int k, int l, int r, int x, int y, ll z) {
        if(l == x && r == y) {
            v[k] += z;
            return ;
        }
        p[k] += (y - x + 1) * z;
        int m = l + r >> 1;
        if(m >= y) {
            add(k << 1, l, m, x, y, z);
        } else if(m < x) {
            add(k << 1 | 1, m + 1, r, x, y, z);
        } else {
            add(k << 1, l, m, x, m, z);
            add(k << 1 | 1, m + 1, r, m + 1, y, z);
        }
    }
    int query(int k, int l, int r, int s, int t, ll A) {
        A += v[k];
        if(l == s && r == t) {
            return (t - s + 1) * A + p[k];
        }
        int m = l + r >> 1;
        if(m >= t) {
            return query(k << 1, l, m, s, t, A);
        } else if(m < s) {
            return query(k << 1 | 1, m + 1, r, s, t, A);
        } else {
            return query(k << 1, l, m, s, m, A) + 
                   query(k << 1 | 1, m + 1, r, m + 1, t, A);
        }
    }
};
void solve() {
    cin >> n;
    vector<int> res(n + 1);
    c.resize(n + 1);
    for(int i = 1; i <= n; i ++) cin >> c[i];
    segtree st(c);
    for(int i = n; i >= 1; i --) {
        int cnt1 = st.query(1, 1, n, 1, i, 0) / i;
        if(cnt1 == 0) break;
        if(i == 1) {
            if(cnt1 > 0) {
                res[i] = 1;
            }
            break;
        }
        st.add(1, 1, n, i - cnt1 + 1, i, -1);
        int cnt2 = st.query(1, 1, n, 1, i - 1, 0) / (i - 1);
        if(cnt1 != cnt2) res[i] = 1;
    }
    for(int i = 1; i <= n; i ++) cout << res[i] << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}