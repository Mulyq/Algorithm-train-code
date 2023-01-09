#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i ++) {
        if(a[i] == a[i - 1]) {
            cout << "NO\n";
            return ;
        }
    }
    bool ok = 1;
    for(int i = 2; i <= n / 2; i ++) {
        vector<int> c(n);
        for(int j = 0; j < n; j ++) {
            c[a[j] % i] ++;
        }
        int d = 0;
        for(int k = 0; k < i; k ++) {
            if(c[k] >= 2) {
                d ++;
            }
        }
        if(d == i) {
            ok = 0;
            break;
        }
    }
    if(ok) {
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
}