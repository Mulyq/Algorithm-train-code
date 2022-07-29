#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        b[i] = a[i] - a[i - 1];
    }
    ll l, r;
    l = r = 0;
    for(int i = 2;i <= n; i ++) {
        if(b[i] < 0) l -= b[i];
        else r += b[i];
    }
    cout << max(l , r) << '\n';
    cout << max(l , r) - min(l, r) + 1 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}