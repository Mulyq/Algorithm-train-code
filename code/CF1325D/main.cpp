#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll u, v;
    cin >> u >> v;
    if(!u && !v) cout << "0\n";
    else if(u > v || (u & 1) != (v & 1)) cout << "-1\n";
    else if(u == v) cout << 1 << '\n' << v << '\n';
    else {
        if((u & (v - u) / 2) == 0) {
            cout << 2 << '\n';
            cout << u + (v - u) / 2 << ' ' << (v - u) / 2 << '\n';
        } else {
            cout << 3 << '\n';
            cout << u << ' ' << (v - u) / 2 << ' ' << (v - u) / 2 << '\n';
        }
    }
}