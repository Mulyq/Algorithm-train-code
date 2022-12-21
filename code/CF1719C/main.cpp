#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int a[MAXN], d[MAXN << 2], pos[MAXN];
int n, q;
void build(int k, int l, int r) {
    if(l == r) {
        d[k] = pos[l];
        return ;
    }
    int m = l + r >> 1;
    build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
    d[k] = min(d[k << 1], d[k << 1 | 1]);
}
int ask(int k, int l, int r, int s, int t) {
    if(l == s && r == t) {
        return d[k];
    }
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t);
    } else if(s >= m + 1) {
        return ask(k << 1 | 1, m + 1, r, s, t);
    } else {
        return min(ask(k << 1, l, m, s, m), ask(k << 1 | 1, m + 1, r, m + 1, t));
    }
}
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    build(1, 1, n);
    while(q --) {
        int i, k;
        cin >> i >> k;
        int t = i;
        if(i == 1) t ++;
        if(k <= t - 2) {
            cout << 0 << '\n';
        } else {
            if(a[i] == n) {
                if(i == 1) {
                    i ++;
                }
                cout << k - i + 2 << '\n';
            } else {
                int r = ask(1, 1, n, a[i] + 1, n);
                if(r < i) cout << 0 << '\n';
                else {
                    cout << max(min(k + 2, r) - i - 1, 1) << '\n';
                }
            }
        }
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
}