#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct BIT {
    int N;
    vector<ll> p;
    BIT(int n) : N(n) {
        p.resize(n + 1);
    }
    void add(int x, int d) {
        for(;x <= N; x += x & -x) {
            (p[x] += d) %= mod;
        }
    }
    ll ask(int x) {
        ll res = 0;
        for(;x; x -= x & -x) {
            (res += p[x]) %= mod;
        }
        return res;
    }
    ll ask(int l, int r) {
        l = max(1, l);
        return (ask(r) - ask(l - 1) + mod) % mod;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> res(n + 1);
    vector<int> len(n + 2);
    int w = 0;
    BIT bit(n);
    // res[0] = 1;
    for(int i = k, j = 1;; i ++, j ++) {
        if(w + i > n) break;
        // res[w + i] = 1;
        w += i;
        bit.add(i, 1);
        len[w] = j;
    }
    for(int i = 1; i <= n; i ++) {
        len[i] = max(len[i], len[i - 1]);
    }
    for(int i = 1; i <= n; i ++) {
        ll temp = bit.ask(i - len[i] - k + 1, i - k + 1);
        if(i - len[i] + 1 <= 0) {
            temp ++;
        }
        // if(res[i] == 0)
        bit.add(i, temp);
        res[i] = res[i] + temp;
        cout << res[i] << '\n';
    }
}