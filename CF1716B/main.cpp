#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        a[i] = i + 1;
    }
    cout << n << '\n';
    for(int i = 0; i < n; i ++) {
        for(auto v : a) {
            cout << v << ' ';
        }
        cout << '\n';
        if(i == n - 1) break;
        swap(a[n - i - 1], a[n - i - 2]);
    }
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