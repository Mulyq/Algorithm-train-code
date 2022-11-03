#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10;
ll qpow(ll x, ll y, ll mod) {
    ll res = 1;
    while(y) {
        if(y & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    int m;
    cin >> n >> m;
    ll T = m * m;
    n = qpow(10, n, T);
    cout << n / m << '\n';
}