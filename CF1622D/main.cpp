#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 5e3 + 10, mod = 998244353;
int n, k;
ll fact[MAXN], inv[MAXN];
ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return res;
}
void init() {
    fact[0] = inv[0] = 1;
    for(int i = 1; i < MAXN; i ++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[MAXN - 1] = qpow(fact[MAXN - 1], mod - 2);
    for(int i = MAXN - 2; i >= 1; i --) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
ll cal(int x, int y) {
    return (fact[x] * inv[y] % mod) * inv[x - y] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pos;
    pos.push_back(0);
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') pos.push_back(i + 1);
    }
    if(k == 0 || pos.size() - 1 < k) {
        cout << 1 << '\n';
        return 0;
    }
    pos.push_back(n + 1);
    ll res = 0;
    for(int l = 0; l + k + 1 < pos.size(); l ++) {
        int r = l + k + 1;
        res += cal(pos[r] - 1 - (pos[l] + 1) + 1, k);
        if(l) {
            res += (mod - cal(pos[r - 1] - 1 - (pos[l] + 1) + 1, k - 1));
        }
        res %= mod;
    }
    cout << (res + mod) % mod << '\n';
}