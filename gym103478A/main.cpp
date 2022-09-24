#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int res = -INF;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        res = max(res, x);
    }
    if(n == 1) {
        for(int i = 0; i < m; i ++) {
            int x;
            cin >> x;
            res += x;
        }
    } else {
        for(int i = 0; i < m; i ++) {
            int x;
            cin >> x;
            if(x > 0) {
                res += x;
            }
        }
    }
    cout << res  << '\n';
}
