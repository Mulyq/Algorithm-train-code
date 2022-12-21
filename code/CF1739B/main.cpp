#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n), a(n);
    for(int i = 0; i < n; i ++) {
        cin >> d[i];
    }
    a[0] = d[0];
    for(int i = 1; i < n; i ++) {
        a[i] = a[i - 1] + d[i];
        if(a[i - 1] - d[i] >= 0 && d[i] != 0) {
            cout << "-1\n";
            return ;
        }
    }
    for(int i : a) {
        cout << i << ' ';
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