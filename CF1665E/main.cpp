#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 10;
int a[MAXN];
struct node {
    vector<int> num;
} d[MAXN << 2];
void build(int k, int l, int r) {
    if(l == r) {
        d[k].num.push_back(a[l]);
        return ;
    }
    int m = l + r >> 1;
    build(k << 1, l , m), build(k << 1 | 1, m + 1, r);
    d[k].num.resize((int)d[k << 1].num.size() + (int)d[k << 1 | 1].num.size());
    merge(d[k << 1].num.begin(), d[k << 1].num.end(), d[k << 1 | 1].num.begin(), d[k << 1 | 1].num.end(), d[k].num.begin());
    d[k].num.resize(min(31, (int)d[k].num.size()));
}
vector<int> query(int k, int l, int r, int s, int t) {
    if(l == s && r == t) {
        return d[k].num;
    }
    int m = l + r >> 1;
    if(m >= t) {
        return query(k << 1, l, m, s, t);
    } else if(m < s) {
        return query(k << 1 | 1, m + 1, r, s, t);
    } else {
        vector<int> t1 = query(k << 1, l, m, s, m), t2 = query(k << 1 | 1, m + 1, r, m + 1, t);
        vector<int> res((int)t1.size() + (int)t2.size());
        merge(t1.begin(), t1.end(), t2.begin(), t2.end(), res.begin());
        res.resize(min(31, (int)res.size()));
        return res;
    }
    
}
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int qq;
    cin >> qq;
    for(int i = 0; i < qq; i ++) {
        int l, r;
        cin >> l >> r;
        auto tt = query(1, 1, n, l , r);
        int res = 2e9;
        for(int i = 0; i < tt.size(); i ++) {
            for(int j = i + 1; j < tt.size(); j ++) {
                res = min(res, tt[i] | tt[j]);
            }
        }
        printf("%d\n", res);
    }
    for(int i = 0; i < MAXN; i ++) {
        d[i].num = vector<int> ();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >>_;
    while(_ --) {
        solve();
    }
    return 0;
}