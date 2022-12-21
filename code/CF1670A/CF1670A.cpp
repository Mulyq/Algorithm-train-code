#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] < 0) {
            cnt ++, a[i] = - a[i];
        }
    }
    for(int i = 0; i < cnt; i ++) {
        a[i] = -a[i];
    }
    for(int i = 1; i < n; i ++) {
        if(a[i] < a[i - 1]) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";

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