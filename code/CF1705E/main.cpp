#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 3e4;
int a[MAXN], d[MAXN << 2], v[MAXN << 2];
int N = 2e5 + 3e4 -10;
void add(int k, int l, int r, int s, int t, int x) {
    if(l == s && r == t) {
        v[k] += x;
        return ;
    }
    d[k] += (t - s + 1) * x;
    int m = l + r >> 1;
    if(m >= t) {
        add(k << 1, l, m, s, t, x);
    } else if(m < s) {
        add(k << 1 | 1, m + 1, r, s, t, x);
    } else {
        add(k << 1, l, m, s, m, x);
        add(k << 1 | 1, m + 1, r, m + 1, t, x);
    }
}
int ask(int k, int l, int r, int s, int t, int p) {
    p += v[k];
    if(l == s && r == t) {
        return (t - s + 1) * p + d[k];
    }
    int m = l + r >> 1;
    if(m >= t) {
        return ask(k << 1, l, m, s, t, p);
    } else if(s > m) {
        return ask(k << 1 | 1, m + 1, r, s, t, p);
    } else {
        return ask(k << 1, l, m, s, m, p) + ask(k << 1 | 1, m + 1, r, m + 1, t, p);
    }
}
int ask_max(int k, int l, int r) {
    if(l == r) {
        return l;
    }
    int m = l + r >> 1;
    if(ask(1, 1, N, m + 1, r, 0)) {
        return ask_max(k << 1, m + 1, r);
    } else {
        return ask_max(k << 1 | 1, l, m);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(ask(1, 1, N, a[i], a[i], 0) == 0) {
            add(1, 1, N, a[i], a[i], 1);
        } else {
            int L = a[i], R = N;
            while(R - L > 1) {
                int M = L + R >> 1;
                if(ask(1, 1, N, a[i], M, 0) < (M - a[i] + 1)) {
                    R = M;
                } else {
                    L = M;
                }
            }
            add(1, 1, N, a[i], L, - 1);
            add(1, 1, N, L + 1, L + 1, 1);
        }
    }
    while(q --) {
        int k, l;
        cin >> k >> l;
        if(ask(1, 1, N, a[k], a[k], 0) == 1) {
            add(1, 1, N, a[k], a[k], - 1);
        } else {
            int L = a[k], R = N;
            while(R - L > 1) {
                int M = L + R >> 1;
                if(!ask(1, 1, N, a[k], M, 0)) {
                    L = M;
                } else {
                    R = M;
                }
            }
            add(1, 1, N, a[k], L, 1);
            add(1, 1, N, L + 1, L + 1, - 1);
        }
        a[k] = l;
        if(ask(1, 1, N, a[k], a[k], 0) == 0) {
            add(1, 1, N, a[k], a[k], 1);
        } else {
            int L = a[k], R = N;
            while(R - L > 1) {
                int M = L + R >> 1;
                if(ask(1, 1, N, a[k], M, 0) < (M - a[k] + 1)) {
                    R = M;
                } else {
                    L = M;
                }
            }
            add(1, 1, N, a[k], L, - 1);
            add(1, 1, N, L + 1, L + 1, 1);
        }
        cout << ask_max(1, 1, N) << '\n';;
    }
}