#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size() == 2) {
        cout << n / 2 + 1 << '\n';
    } else {
        cout << n << '\n';
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
}