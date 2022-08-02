#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct segtre {
    int N;
    vector<ll> p, v;
    segtre(int n) : N(n) {
        p.resize(n << 2 | 1);
        v.resize(n << 2 | 1);
    }
    void build(int k, int l, int r, vector<int> &a) {
        if(l == r) {
            p[k] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(k << 1, l, m, a), build(k << 1 | 1, m + 1, r, a);
        p[k] = p[k << 1] + p[k << 1 | 1];
    }
    void push_down(int k, int l, int r) {
        v[k << 1] += v[k], v[k << 1 | 1] += v[k];
        v[k] = 0;
    }
    void up_data(int k, int l, int r) {
        int m = l + r >> 1;
        p[k] = p[k << 1] + (m - l + 1) * v[k << 1] + p[k << 1 | 1] + (r - m) * v[k << 1 | 1];
    }
    void add(int k, int l, int r, int s, int t, int x) {
        if(l == s && r == t) {
            v[k] += x;
            return ;
        }
        push_down(k, l, r);
        int m = l + r >> 1;
        if(m >= t) {
            add(k << 1, l, m, s, t, x);
        } else if(s >= m + 1) {
            add(k << 1 | 1, m + 1, r, s, t, x);
        } else {
            add(k << 1, l, m, s, m, x) , add(k << 1 | 1, m + 1, r, m + 1, t, x);
        }
        up_data(k, l, r);
    }
    ll ask(int k, int l, int r, int s, int t) {
        if(l == s && r == t) {
            return p[k] + v[k] * (t - s + 1);
        }
        push_down(k, l, r);
        int m = l + r >> 1;
        ll res = 0;
        if(m >= t) {
            res = ask(k << 1, l, m, s, t);
        } else if(s >= m + 1) {
            res = ask(k << 1 | 1, m + 1, r, s, t);
        } else {
            res = ask(k << 1, l, m, s, m) + ask(k << 1 | 1, m + 1, r, m + 1, t);
        }
        up_data(k, l, r);
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    segtre st(n);
    st.build(1, 1, n, a);
    while(q --) {
        int op, l, r, x;
        cin >> op;
        if(op == 1) {
            cin >> l >> r >> x;
            st.add(1, 1, n, l, r, x);
        } else {
            cin >> l >> r;
            cout << st.ask(1, 1, n, l, r) << '\n';
        }
    }
}