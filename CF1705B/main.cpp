#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll res = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int i = 0;
    while(a[i] == 0) i ++;
    for(; i < n - 1; i ++) {
        res += max(a[i] , 1);
    }
    cout << res  << '\n';
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