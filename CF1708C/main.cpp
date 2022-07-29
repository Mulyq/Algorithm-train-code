#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    string s;
    int c = 0;
    for(int i = n - 1; i >= 0; i --) {
        if(a[i] > c && c < q) {
            c ++;
            s.push_back('1');
        } else if(a[i] <= c) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
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