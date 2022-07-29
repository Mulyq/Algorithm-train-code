#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int n, m;
struct node {
    int l, r, val;
};
vector<node> d;
int res = 0;
void build(int l, int r, int i) {
    d[i].l = l, d[i].r = r;
    if(l == r) {
        d[i].val = m;
        return ;
    }
    int m = l + (r - l >> 1);
    
    build(l, m, i << 1);
    build(m + 1, r, i << 1 | 1);
    d[i].val = max(d[i << 1].val, d[(i << 1) | 1].val);
}
void query(int a, int i) {
    if(d[i].l == d[i].r) {
        if(d[i].val == m) {
            res ++;
        }
        d[i].val -= a;
        return ;
    }
    if(d[i << 1].val >= a) {
        query(a, i << 1);
    } else {
        query(a, (i << 1) | 1);
    }
    d[i].val = max(d[i << 1].val, d[(i << 1) | 1].val);
}

vector<int> a;
void solve() {
    cin >> n >> m;
    d.resize(4 * n  + 2);
    a.resize(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    res = 0;
    build(1, n, 1);
    for(int i = 1; i <= n; i ++) {
        query(a[i], 1);
    }
    cout << res << ' ';

    map<int, int> cnt;
    cnt[m] = n;
    for(int i = 1; i <= n; i ++) {
        auto it = cnt.lower_bound(a[i]);
        it->second --;
        cnt[it->first - a[i]] ++;
        if(it->second == 0) {
            cnt.erase(it);
        }
    }
    res = 0;
    for(auto it : cnt) {
        if(it.first != m)
            res += it.second;
    }
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}