#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    iota(f.begin(), f.end(), 1);
    // for(int i = 0; i < n - 2; i ++) {
    //     cout << f[i] << ' ';
    // }
    // cout << f[n - 1] << ' ' << f[n - 2] << '\n';
    reverse(f.begin(), f.end());
    for(int i = 0; i < n - 1; i ++) {
        for(int i = 0; i < n; i ++) {
            cout << f[i] << ' ';
        }
        cout << "\n";
        swap(f[n - i - 1], f[n - i - 2]);
    }
        for(int i = 0; i < n; i ++) {
            cout << f[i] << ' ';
        }
        cout << "\n";
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