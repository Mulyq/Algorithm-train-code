#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
vector<ll> d(N * 4);
vector<ll> b;
int n, C;
void build(int k, int l, int r) {
    if(l == r) {
        d[k] = b[l];
        return;
    }
    int m = l + r >> 1;
    build(k << 1, l, m);
    build(k << 1 | 1, m + 1, r);
    d[k] = max(d[k << 1], d[k << 1 | 1]);
}
void ask(int k, int l, int r, ll x) {
    if(l == r) {
        cout << l << '\n';
        return;
    }
    int m = l + r >> 1;
    if(d[k << 1] > x) {
        ask(k << 1, l, m, x);
    } else {
        ask(k << 1 | 1, m + 1, r, x);
    }
}
void solve() {
    cin >> n >> C;
    b.resize(C + 1, 0);
    for(int i = 1; i <= n; i ++) {
        int c;
        ll d, h;
        cin >> c >> d >> h;
        b[c] = max(b[c], d * h);
    }
    for(int i = 1; i <= C; i ++) {
        for(int j = 2; j * i <= C; j ++) {
            b[i * j] = max(b[i * j], b[i] * j);
        }
    }
    build(1, 1, C);
    int m;
    cin >> m;
    while(m --) {
        ll D, H;
        cin >> D >> H;
        if(d[1] <= D * H) {
            cout << -1 << ' ';
            continue;
        }
        ask(1, 1, C, D * H);
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