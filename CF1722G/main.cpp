#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int A = 0, B = 0;
    for(int i = 0, j = 2; i < n - 1; i ++, j ++) {
        a[i] = i + j;
        if(i & 1) {
            B ^= a[i];
        } else {
            A ^= a[i];
        }
    }
    a[n - 1] = A^B;
    if((n - 1) & 1) {
        B ^= a[n - 1];
    } else {
        A ^= a[n - 1];
    }
    // cout << A << ' ' << B << '\n';
    for(int v : a) {
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