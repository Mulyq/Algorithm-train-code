#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'W') a[i + 1] ++;
    }
    for(int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
    }
    int res = INF;
    for(int i = 0; i < n; i ++) {
        int j = i + k;
        if(j > n) break;
        res = min(a[j] - a[i], res);
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