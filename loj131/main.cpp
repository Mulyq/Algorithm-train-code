#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, q;
struct BIT {
    int N;
    vector<ll> p;
    BIT(int n) : N(n) {
        p.resize(N);
    }
    void add(int x, int d) {
        for(; x <= N; x += x & - x) {
            p[x] += d;
        }
    }
    ll ask(int x) {
        ll res = 0;
        for(; x; x -= x & - x) {
            res += p[x];
        } 
        return res;
    }
    ll ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    BIT bit(n + 1);
    while(q --) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, d;
            cin >> l >> r >> d;
            bit.add(l, d);
            bit.add(r + 1, - d);
        } else {
            int x;
            cin >> x;
            cout << a[x] + bit.ask(x) << '\n';
        }
    }
}