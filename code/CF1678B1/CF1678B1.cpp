#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        char x;
        cin >> x;
        a[i] = x - '0';
    }
    int res = 0;
    int cnt = 1;
    for(int i = 1; i < n; i ++) {
        if(a[i] != a[i - 1] ) {
            if(cnt % 2 == 1) {
                a[i] = a[i - 1];
                res ++;
                cnt ++;
            } else {
                cnt = 1;
            }
        } else {
            cnt ++;
        }
    }
    cout << res << '\n';
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