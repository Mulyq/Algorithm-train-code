#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int n, m, q;
int d[MAXN << 2], a[MAXN];
void build(int k, int l, int r) {
    if(l == r) {
        d[k] = a[l];
        return ;
    }
    int m = l + r >> 1;
    build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
    d[k] = max(d[k << 1], d[k << 1 | 1]);
}
int ask(int k, int l, int r, int s, int t) {
    if(l == s && r == t) {
        return d[k];
    }
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t);
    } else if(s >= m + 1)  {
        return ask(k << 1 | 1, m + 1, r, s, t);
    } else {
        return max(ask(k << 1, l, m, s, m), ask(k << 1 | 1, m + 1, r, m + 1, t));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> a[i];
    }
    build(1, 1, m);
    int q;
    cin >> q;
    while(q --) {
        int xs, ys, xt, yt, k;
        cin >> xs >> ys >> xt >> yt >> k;
        if(abs(ys - yt) % k != 0 || abs(xs - xt) % k != 0) {
            cout << "NO\n";
            continue;
        }
        if(ys == yt) {
            if(abs(xs - xt) % k == 0) {
                cout <<"YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        if(ys > yt) swap(ys, yt);
        int d = ask(1, 1, m, ys, yt);
        // cout << ys << ' ' << yt << ' ' << d << '\n';
        int w = (n - xs) / k;
        w = xs + k * w;
        // cout << w << '\n';
        while(w > n) w -= k;
        if(w > d) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}