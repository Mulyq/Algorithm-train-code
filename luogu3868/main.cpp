#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b) {
        exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1, y =0;
    }
}
ll inv(ll a, ll b) {
    ll x, k;
    exgcd(a, b, x, k);
    return (x + b) % b;
}
ll binmul(ll a, ll b, ll m) {
    ull c = (ull)a * b - (ull)((long double)a / m * b + 0.5L) * m;
    return (c + m) % m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll M = 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
        M *= b[i];
    }
    ll res = 0;
    for(int i = 0; i < n; i ++) {
        ll m = M / b[i];
        (res += binmul(binmul(a[i], m, M) , inv(m, b[i]) , M)) %= M;
    }
    cout << res << '\n';
}