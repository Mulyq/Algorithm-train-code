#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define int ll
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for(int i = 0; i < k; i ++) {
        cin >> s[i];
    }
    if(k == 1) {
        cout << "YES\n";
        return ;
    }
    vector<int> a;
    for(int i = 0; i < k - 1; i ++) {
        a.push_back(s[i + 1] - s[i]);
    }
    for(int i = 0; i < a.size() - 1; i ++) {
        if(a[i] > a[i + 1]) {
            cout << "NO\n";
            return ;
        }
    }
    int c = n - k + 1;
    if(a[0] * c < s[0]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}