#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int M = 1e5 + 10;
ll a[M], d[4 * M], v[4 * M];
int n, m;
void build(int k, int l, int r) {
    v[k] = 0;
    if(l == r) {
        d[k] = a[l];
        return ;
    }
    int m = l + r >> 1;
    build(k << 1 ,l , m);
    build(k << 1 | 1, m + 1, r);
    d[k] = d[k << 1] + d[k << 1 | 1];
}
void insert(int k, int l, int r, int x, int y, ll z) {
    if(l == x && r == y) {
        v[k] += z;
        return ;
    }
    d[k] += (y - x + 1) * z;
    int m = l + r >> 1;
    if(m >= y) {
        insert(k << 1, l, m, x, y, z);
    } else if(m < x) {
        insert(k << 1 | 1, m + 1, r, x, y, z);
    } else {
        insert(k << 1, l, m, x, m, z);
        insert(k << 1 | 1, m + 1, r, m + 1, y, z);
    }
}
ll ask(int k, int l, int r, int x, int y, ll p) {
    p += v[k];
    if(l == x && r == y) {
        return (y - x + 1) * p + d[k]; 
    }
    int m = l + r >> 1;
    if(m >= y) {
        return ask(k << 1, l, m, x, y, p);
    } else if(m < x) {
        return ask(k << 1 | 1,m + 1, r, x, y, p);
    } else {
        return ask(k << 1, l, m, x, m, p) + ask(k << 1 | 1, m + 1, r, m + 1, y , p);
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for(int i = 0; i < m; i ++) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            insert(1, 1, n, x, y, z);
        } else {
            int x, y;
            cin >> x >> y;
            cout << ask(1 ,1 ,n ,x , y, 0) << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}