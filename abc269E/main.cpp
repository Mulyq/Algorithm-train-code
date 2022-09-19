#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int ask(int a1, int b1, int a2, int b2) {
    cout << "? " << a1 << ' ' << a2 << ' ' << b1 << ' ' << b2 << '\n';
    int res;
    cin >> res;
    return res;
}
int main() {
    int n, x, y;
    cin >> n;
    int xl = 1, xr = n;
    int yl = 1, yr = n;
    while(xl != xr) {
        int m = xl + xr >> 1;
        int c = ask(xl, 1, m, n);
        if(c == m - xl) xr = m;
        else xl = m + 1;
    }
    while(yl != yr) {
        int m = yl + yr >> 1;
        int c = ask(1, yl, n, m);
        if(c == m - yl) yr = m;
        else yl = m + 1;
    }
    cout << "! " << xl << ' ' << yl << '\n';
}