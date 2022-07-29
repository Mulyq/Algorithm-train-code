#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n = 10;
    vector<int> a(1);
    int now = 0; 
    int res = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < 3; i ++) {
        now = a[now];
    }
    cout << now ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}