#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void exgcd(ll a, ll b, ll &x, ll &k) {
    if(b) {
        exgcd(b, a % b, k, x);
        k -= (a / b) * x;
    } else {
        x = 1, k = 0;
    }
}
ll inv(ll a, ll b) {
    ll x, k;
    exgcd(a, b, x, k);
    return (x + b) % b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll M = 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i] >> b[i];
        M *= a[i];
    }
    ll x = 0;
    for(int i = 0; i < n; i ++) {
        ll m = M / a[i];
        (x += (b[i] * m % M) * inv(m, a[i]) % M) %= M;
    }
    cout << x << '\n';
}