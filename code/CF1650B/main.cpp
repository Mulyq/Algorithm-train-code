#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int l, r, a;
    cin >> l >> r >> a;
    int k = (r + 1) / a;
    int res = 0;
    int w = a * k - 1;
    if(w >= l) {
        res = w / a + w % a;
    } else {
        res = r / a + r % a;
    }
    cout << res << '\n';
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