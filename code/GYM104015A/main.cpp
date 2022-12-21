#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int res = n;
    for(int i = 1; a * i + b * (i + 1) <= n; i ++) {
        for(int j = i + 1; a * i + b * j <= n; j ++) {
            res = min(res, n - a * i - b * j);
        }
    }
    cout << res << '\n';
}