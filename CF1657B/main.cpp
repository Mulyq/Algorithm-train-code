#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, B, x, y;
    cin >> n >> B >> x >> y;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        if(x >= -y) {
            if(a[i - 1] + x <= B) {
                a[i] = a[i - 1] + x;
            } else {
                a[i] = a[i - 1] - y;
            }
        } else {
            if(a[i - 1] - y <= B) {
                a[i] = a[i - 1] - y;
            } else {
                a[i] = a[i - 1] + x;
            }
        }
    }
    ll res = 0;
    for(int i = 1 ;i <= n; i ++) {
        res += a[i];
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