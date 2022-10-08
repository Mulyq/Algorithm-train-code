#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
const int inv = 499122268;
#define int ll
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    while(q --) {
        ll res = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll t1 = 0, t2 = 0;
        if((a + c) % 2 == 0) {
            if((b + c) % 2 == 0) {
                int len = (b - a) / 2 + 1;
                t1 += ((a - 1) * m + c + (b - 1) * m + c) * len / 2 % mod;
                t2 += ((a * m + c + 1) + (b - 2) * m + c + 1) * (len - 1) / 2 % mod;
                int x = (d - c) / 2 + 1;
                res += (t1 + (x - 1) * 2 * len + t1) * x / 2 % mod;
                int y = (d - c - 1) / 2 + 1;
                if(d == c) y = 0;
                res += (t2 + (y - 1) * 2 * (len - 1) + t2) * y / 2 % mod;
            } else {
                int len = (b - a) / 2;
                t1 += ((a - 1) * m + c + (b - 3) * m + c) * len / 2 % mod;
                t2 += ((a * m + c + 1) + (b - 1) * m + c + 1) * len / 2 % mod;
                int x = (d - c) / 2 + 1;
                res += (t1 + (x - 1) * 2 * len + t1) * x / 2 % mod;
                int y = (d - c - 1) / 2 + 1;
                if(d == c) y = 0;
                res += (t2 + (y - 1) * 2 * (len - 1) + t2) * y / 2 % mod;
            }
        } else {
            if((b + c) % 2 == 0) {
                int len = (b - a) / 2 + 1;
                t2 += ((a - 1) * m + c + 1 + (b - 2) * m + c + 1) * len / 2;
                t1 += ((a * m + c) + (b - 1) * m + c) * len / 2;
                int x = (d - c) / 2 + 1;
                res += (t1 + (x - 1) * 2 * len + t1) * x / 2 % mod;
                int y = (d - c - 1) / 2 + 1;
                if(d == c) y = 0;
                res += (t2 + (y - 1) * 2 * len + t2) * y / 2 % mod;
            } else {
                int len = (b - a) / 2;
                t2 += ((a - 1) * m + c + 1 + (b - 1) * m + c + 1) * (len + 1) / 2;
                t1 += ((a * m + c) + (b - 2) * m + c) * len / 2;
                int x = (d - c) / 2 + 1;
                res += (t1 + (x - 1) * 2 * len + t1) * x / 2 % mod;
                int y = (d - c - 1) / 2 + 1;
                if(d == c) y = 0;
                res += (t2 + (y - 1) * 2 * (len + 1) + t2) * y / 2 % mod;
            }
        }
        cout << res << '\n';
    }
}