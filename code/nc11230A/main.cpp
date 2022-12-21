#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int a[4], k;
    for(int i = 0; i < 4; i ++) {
        cin >> a[i];
    }
    cin >> k;
    for(int i = 0; i < 4; i ++) {
        cout << max(0, k - a[i]) << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    while(_ --) {
        solve();
    }
    return 0;
}