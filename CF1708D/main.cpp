#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int l = 0, r = n;
    for(int j = 0; ; j ++) {
        if(l == r - 1) {
            cout << a[l] << '\n';
            return ;
        }
        for(int i = n - 1; i > l; i --) {
            a[i] -= a[i - 1];
        }
        while(a[l] == 0 && l < r) l ++;
        if(l == r) {
            cout << "0\n";
            return;
        }
        if(l > j) {
            sort(a.begin() + l, a.end());
        } else {
            sort(a.begin() + l + 1, a.end());
            l ++;
        }
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