#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, e;
    cin >> n >> e;
    int all = 0;
    for(int i= 0; i < n; i ++) {
        int x;
        cin >> x;
        all  += x;
    }
    cout << max(0 , all - e) << '\n';
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