#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
void solve() {
    vector<int> a(110);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[x] ++;
    }
    int res = 0;
    res = n + 1;
    for(int i = 0; i <= 100; i ++) {
        if(i == 0 && a[i] > 0) {
            res = n - a[i];
            break;
        }
        if(a[i] >= 2) {
            res --;
            break;
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