#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxx = -1;
    ll sum = 0;
    bool ok = 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
        maxx = max(maxx, a[i]);
        if(a[i] != 0) {
            ok = 0;
        }
    }
    if(ok) {
        cout << 0 << '\n';
        return ;
    }
    sum -= maxx;
    if(maxx - sum <= 0) {
        cout << 1 << '\n';
    } else {
        cout << maxx - sum << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}