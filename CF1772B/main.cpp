#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    vector<int> a(4);
    for(int i = 0; i < 4; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < 4; i ++) {
        if(a[0] < a[2] && a[0] < a[1]) {
            if(a[1] < a[3] && a[2] < a[3]) {
                cout << "YES\n";
                return;
            }
        }
        int t = a[0];
        a[0] = a[2], a[2] = a[3], a[3] = a[1], a[1] = t;
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}