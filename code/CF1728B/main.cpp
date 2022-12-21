#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> res(n);
    res[n - 1] = n, res[n - 2] = n - 1;
    if(n % 2 == 0) {
        for(int i = 0; i < n - 2; i ++) {
            res[i] = n - 2 - i;
        }
    } else {
        for(int i = 0; i < 3; i ++) {
            res[i] = i + 1;
        }
        for(int i = 3; i < n - 2; i ++) {
            res[i] = n - 2 - i + 3;
        }
    }
    for(int v : res) {
        cout << v << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}