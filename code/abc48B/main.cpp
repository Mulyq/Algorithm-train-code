#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a , b, x;
    cin >> a >> b >> x;
    cout << max(0ll, b / x - (a + x - 1) / x + 1);
}