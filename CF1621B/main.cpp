#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x7f7f7f7f;

void solve() {
    int n;
    cin >> n;
    struct seg {
        int l, r, c;
    };
    
    vector<seg> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].l >> a[i].r >> a[i].c;
    }
    int res = INF;
    int L = INF, R = -INF;
    int cl, cr;
    for(int i = 0; i < n; i ++) {
        if(a[i].l < L) {
            cl  = res = INF;
            L = a[i].l;
        }
        if(a[i].r > R) {
            cr = res = INF;
            R = a[i].r;
        }
        if(a[i].l == L) {
            cl = min(cl, a[i].c);
        }
        if(a[i].r == R) {
            cr = min(cr, a[i].c);
        }
        if(a[i].l == L && a[i].r == R) {
            res = min(res, a[i].c);
        }
        cout << min(res, cl + cr) << '\n';
    }
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