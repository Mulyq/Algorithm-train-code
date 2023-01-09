#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> q(n);
    int x = 1;
    int c = 0;
    for(int i = 0; i < n; i ++) {
        cin >> q[i];
        if(q[i] == x) {
            c ++;
            x ++;
        }
    }
    cout << (n - c + k - 1) / k << '\n';
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