#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e4 + 10, mod = 998244353;
int n, m, BS;
ll a[MAXN], b[MAXN], s[MAXN], v[410];
bool cmp(ll x, ll y) {
    return (s[x] + v[x / BS]) * b[x] < (s[y] + v[y / BS]) * b[y];
}
void op1(int l, int r, int w) {
    int bl = l / BS, br = r / BS;
    if(bl == br) {
        for(int i = bl * BS; i < (bl + 1) * BS; i ++) {
            if(a[i] >= l && a[i] <= r) {
                a[i] += w;
            }
        }
    } else {
        for(int i = bl * BS; i < (bl + 1) * BS; i ++) {
            if(a[i] >= l && a[i] <= r) {
                a[i] += w;
            }
        }

        for(int i = br * BS; i < (br + 1) * BS; i ++) {
            if(a[i] >= l && a[i] <= r) {
                a[i] += w;
            }
        }
        
        for(int i = bl + 1; i < br; i ++) {
            v[i] += w;
        }
    }
}
void op2(int l, int r) {
    int bl = l / BS, br = r / BS;
    swap(b[l], b[r]);
    for(int i = bl * BS; i < (bl + 1) * BS; i ++) {
    }
    sort(b + bl * BS, b + (bl + 1) * BS);
    for(int i = br * BS; i < (br + 1) * BS; i ++) {
    }
    sort(b + br * BS, b + (br + 1) * BS);
}
ll op3(int l, int r) {
    ll res = 0;
    int bl = l / BS, br = r / BS;
    for(int i = l; i < (bl + 1) * BS; i ++) {
        res = max(res, (a[i] + v[bl]) * b[i]);
    }
    for(int i = br * BS; i <= r; i ++) {
        res = max(res, (a[i] + v[br]) * b[i]);
    }
    for(int i = bl + 1; i < br; i ++) {
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(a, 0x7f, sizeof a);
    memset(b, 0x7f, sizeof b);
    BS = sqrt(n) + 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        s[i] = a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    for(int i = 0; i * BS <= n; i ++) {
        sort(s + i * BS, s + (i + 1) * BS, cmp);
    }
    while(m --) {
        int op, l, r, w;
        cin >> op >> l >> r;
        if(op == 1) {
            cin >> w;
            op1(l, r, w);
        } else if(op == 2) {
            op2(l, r);
        } else {
            cout << op3(l, r) << '\n';
        }
    }
}