#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5, mod = 998244353;
int n, m;
ll a[MAXN], s[MAXN], v[1110], t1[1110], t2[1110];
int BS;
void add(int l, int r, int k) {
    int bl = l / BS, br = r / BS, c1 = 0, c2 = 0;
    if(bl == br) {
        for(int i = bl * BS; i < (bl + 1) * BS; i ++) {
            if(i >= l && i <= r) {
                a[i] += k;
                t1[c1 ++] = a[i];
            } else {
                t2[c2 ++] = a[i];
            }
        }
        merge(t1, t1 + c1, t2, t2 + c2, s + bl * BS);
    } else {
        for(int i = l; i < (bl + 1) * BS; i ++) {
            if(i >= l) {
                a[i] += k;
                t1[c1 ++] = a[i];
            } else {
                t2[c2 ++] = a[i];
            }
        }
        merge(t1, t1 + c1, t2, t2 + c2, s + bl * BS);
        c1 = c2 = 0;
        for(int i = br * BS; i < (br + 1) * BS; i ++) {
            if(i <= r) {
                a[i] += k;
                t1[c1 ++] = a[i];
            } else {
                t2[c2 ++] = a[i];
            }
        }
        merge(t1, t1 + c1, t2, t2 + c2, s + br * BS);
        for(int i = bl + 1; i < br; i ++) {
            v[i] += k;
        }
    }
}
int check(int l, int r, ll k) {
    int bl = l / BS, br = r / BS;
    int res = 0;
    if(bl == br) {
        res += lower_bound(s + l, s + r + 1, k - v[bl]) - (s + l);
    } else {
        res += lower_bound(s + l, s + (bl + 1) * BS, k - v[bl]) - (s + l);
        res += lower_bound(s + br * BS, s + r + 1, k - v[br]) - (s + br * BS);
        for(int i = bl + 1; i < br; i ++) {
            res += lower_bound(s + i * BS, s + (i + 1) * BS, k - v[i]) - (s + i * BS);
        }
    }
    return res;
}
ll query(int l, int r, int k) {
    ll L = 2e9, R = -2e9;
    int bl = l / BS, br = r / BS;
    if(bl == br) {
        for(int i = l; i <= r; i ++) {
            s[i] = a[i];
        }
        sort(s + l, s + r + 1);
        return s[l + k - 1] + v[bl];
    } else {
        for(int i = l; i < (bl + 1) * BS; i ++) {
            s[i] = a[i];
        }
        sort(s + l, s + (bl + 1) * BS);
        L = min(s[l], L), R = max(s[(bl + 1) * BS - 1], R);
        
        for(int i = br * BS; i <= r; i ++) {
            s[i] = a[i];
        }
        sort(s + br * BS, s + r + 1);
        L = min(L, s[br * BS]), R = max(R, s[r]);
        for(int i = bl + 1; i < br; i ++) {
            L = min(L, s[i * BS] + v[i]), R = max(R, s[(i + 1) * BS - 1] + v[i]);
        }
    }
    L --, R ++;
    while(L + 1 < R) {
        ll M = (L + R) / 2;
        if(check(l, r, M) >= k) {
            R = M;
        } else {
            L = M;
        }
    }
    return L;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    BS = sqrt(n) + 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        s[i] = a[i];
    }
    for(int i = 0; i < BS; i ++) {
        sort(s + i * BS, s + (i + 1) * BS);
    }
    while(m --) {
        int op, l, r, k;
        cin >> op >> l >> r >> k;
        l --, r --;
        if(op == 2) {
            add(l, r, k);
        } else {
            if(r - l + 1 < k) {
                cout << "-1\n";
            } else {
                cout << query(l, r, k) << '\n';
            }
        }
    }
}