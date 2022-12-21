#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, m;
int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return (a - b + mod) % mod; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int> res(n + 1), ex(m + 1, 1), mpow(n + 1);
    mpow[0] = 1;
    for(int i = 1; i <= n; i ++) {
        mpow[i] = 1ll * m * mpow[i - 1] % mod;
    }
    for(int i = 1; i <= n; i ++) {
        for(int x = 1; x <= m; x ++) {
            if(i >= 2) {
                int t = ex[x];
                ex[x] = sub(mpow[i - 1], mpow[i - 2]) + mul(m - x, (mod + t - mpow[i - 2]) % mod);
                ex[x] %= mod;
            }
        }
        for(int x = 1; x <= m; x ++) {
            res[i] += add(res[i - 1], ex[x]);
            res[i] %= mod;
        }
    }
    cout << res[n] % mod;
}