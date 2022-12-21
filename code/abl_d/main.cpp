#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 3e5 + 10, mod = 998244353;
int st[MAXN << 2];
void add(int k, int l, int r, int x, int y) {
    if(l == r) {
        st[k] = y;
        return ;
    }
    int m = l + r >> 1;
    if(x <= m) {
        add(k << 1, l, m, x, y);
    } else {
        add(k << 1 | 1, m + 1, r, x, y);
    }
    st[k] = max(st[k << 1], st[k << 1| 1]);
}
int ask(int k, int l, int r, int s, int t) {
    if(s == l && r == t) {
        return st[k];
    }
    int m = l + r >> 1;
    if(t <= m) {
        return ask(k << 1, l, m, s, t);
    } else if(s >= m + 1) {
        return ask(k << 1 | 1, m + 1, r, s, t);
    } else {
        return max(ask(k << 1, l, m, s, m), ask(k << 1 | 1, m + 1, r, m + 1, t));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] += 1;
    }
    for(int i = 0; i < n; i ++) {
        int L = max(1, a[i] - k), R = min(k + a[i], MAXN);
        int len = ask(1, 1, MAXN, L, R);
        add(1, 1, MAXN, a[i], len + 1);
    }
    cout << ask(1, 1, MAXN, 1, MAXN);
}