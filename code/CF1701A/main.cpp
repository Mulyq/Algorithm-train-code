#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int x = 0;
    for(int i = 0; i < 4; i ++) {
        int t;
        cin >> t;
        x += t;
    }
    if(x == 0) cout << "0\n";
    else if(x == 4) cout << "2\n";
    else cout << "1\n";
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