#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1100000, mod = 998244353;
int n, q, BS;
int a[MAXN], v[1010], s[MAXN];
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
        for(int i = bl + 1; i < br; i ++) {
            v[i] += k;
        }
        for(int i = br * BS; i <= r; i ++) {
            a[i] += k;
        }
        for(int i = br * BS; i < (br + 1) * BS; i ++) {
            s[i] = a[i];
        }
        sort(s + br * BS, s + (br + 1) * BS);
    }
}
int query(int l, int r, int c) {
    int bl = l / BS, br = r / BS;
    int C, res = 0;
    if(bl == br) {
        C = c - v[bl];
        for(int i = l; i <= r; i ++) {
            if(a[i] >= C) res ++;
        }
    } else {
        C = c - v[bl];
        for(int i = l; i < (bl + 1) * BS; i ++) {
            if(a[i] >= C) res ++;
        }
        for(int i = bl + 1; i < br; i ++) {
            C = c - v[i];
            res += BS - (lower_bound(s + BS * i, s + BS * (i + 1), C) - (s + BS * i));
        }
        C = c - v[br];
        for(int i = br * BS; i <= r; i ++) {
            if(a[i] >= C) res ++;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(a, 0x3f3f3f3f, sizeof a);
    cin >> n >> q;
    BS = sqrt(n) + 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        s[i] = a[i];
    }
    for(int i = 0; i <= BS; i ++) {
        sort(s + i * BS, s + (i + 1) * BS);
    }
    while(q --) {
        char op;
        int l, r, x;
        cin >> op >> l >> r >> x;
        l --, r --;
        if(op == 'M') add(l, r, x);
        else cout << query(l, r, x) << '\n';
    }
}