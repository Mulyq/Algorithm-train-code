#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    int l = INF, r = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    l --, r ++;
    while(r - l > 1) {
        bool ok = 0;
        int m = l + r >> 1;
        vector<int> t = a;
        for(int i = 0; i < n; i ++) {
            t[i]  = abs(t[i] - m);
        }
        for(int i = 1; i < n; i ++) {
            if(a[i] >= a[i - 1]) {
                if(t[i] < t[i - 1]) {
                    r = m;
                    ok = 1;
                    break;
                }
            }
            if(a[i] < a[i - 1]) {
                if(t[i] < t[i - 1]) {
                    l = m;
                    ok = 1;
                    break;
                }
            }
        }
        if(!ok) {
            cout << m << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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