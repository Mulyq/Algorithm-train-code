#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int a[MAXN], s[MAXN], v[410];
int BS;
void add(int l, int r, int k) {
    int bl = l / BS, br = r / BS;
    if(bl == br) {
        for(int i = l; i <= r; i ++) {
            a[i] += k;
        }
        for(int i = bl * BS; i < (bl + 1) * BS; i ++) {
            s[i] = a[i];
        }
        sort(s + bl * BS, s + (bl + 1) * BS);
    } else {
        for(int i = l; i < (bl + 1) * BS; i ++) {
            a[i] += k;
        }
        for(int i = bl * BS; i < (bl + 1) * BS; i ++) {
            s[i] = a[i];
        }
        sort(s + bl * BS, s + (bl + 1) * BS);
        for(int i = br * BS; i <= r; i ++) {
            a[i] += k;
        }
        for(int i = br * BS; i < (br + 1) * BS; i ++) {
            s[i] = a[i];
        }
        sort(s + br * BS, s + (br + 1) * BS);
        for(int i = bl + 1; i < br; i ++) {
            v[i] += k;
        }
    }
}
int query(int l, int r, int x) {
    int bl = l / BS, br = r / BS, res = -1;
    if(bl == br) {
        for(int i = l; i <= r; i ++) {
            if(a[i] + v[bl] < x) {
                res = max(res, a[i] + v[bl]);
            }
        }
    } else {
        for(int i = l; i < (bl + 1) * BS; i ++) {
            if(a[i] + v[bl] < x) {
                res = max(res, a[i] + v[bl]);
            }
        }
        for(int i = br * BS; i <= r; i ++) {
            if(a[i] + v[br] < x) {
                res = max(res, a[i] + v[br]);
            }
        }
        for(int i = bl + 1; i < br; i ++) {
            int it = lower_bound(s + i * BS, s + (i + 1) * BS, x - v[i]) - s - 1;
            if(it >= i * BS && s[it] + v[i] < x) {
                res = max(res, s[it] + v[i]);
            }
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(s, 0x3f, sizeof s);
    int n;
    cin >> n;
    BS = sqrt(n) + 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        s[i] = a[i];
    }
    for(int i = 0; i <= BS; i ++) {
        sort(s + i * BS, s + (i + 1) * BS);
    }
    for(int i = 0; i < n; i ++) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;
        l --, r --;
        if(op == 0) add(l, r, x);
        else cout << query(l, r, x) << '\n';
    }
}