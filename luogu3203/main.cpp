#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 400, mod = 998244353;
int n, BS, m, B;
int a[MAXN], c[MAXN], to[MAXN];
void upd(int l, int r) {
    for(int i = r; i >= l; i --) {
        if(i + a[i] > r) {
            c[i] = 1;
            to[i] = i + a[i];
        } else {
            c[i] = c[i + a[i]] + 1;
            to[i] = to[i + a[i]];
        }
    }
}
int query(int x) {
    int res = 0, pos = x;
    do {
        res += c[pos];
        pos = to[pos];
    } while(pos < n);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    BS = sqrt(n) + 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i += BS) {
        upd(i, min(n - 1, i + BS - 1));
    }
    cin >> m;
    while (m --) {
        int op, x, y;
        cin >> op >> x;
        if(op == 1) {
            cout << query(x) << '\n';
        } else {
            cin >> y;
            a[x] = y;
            int b = x / BS;
            upd(b * BS, min(n - 1, (b + 1) * BS - 1));
        }
    }
}