#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int x;
    cin >> x;
    x --;
    vector<int> a(3);
    for(int i = 0; i < 3; i ++) {
        cin >> a[i];
    }
    int cnt = 0;
    while(x != -1) {
        x = a[x] - 1;
        cnt ++;
    }
    if(cnt == 3) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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