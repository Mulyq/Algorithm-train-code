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
    struct seg {
        bool l, r;
    };
    vector<bool> ss(n);
    for(int i = 0; i <= 14; i ++) {
        for(int l = 0; l < n; l ++) {
            if(a[l] & (1 << i)) {
                int r = l + 1;
                while(r < n && a[r] & (1 << i)) r ++;
                ss[l] = 1, ss[r - 1] = 1;
                l = r - 1;
            }
        }
    }
    int res = 0;
    bool ok = 1;
    for(int i = 0; i < n; i ++) {
        if(a[i]) {
            ok = 0;
            break;
        }
    }
    if(ok) cout << "0\n";
    else {
        for(int i = 0; i < n; i ++) {
            if(ss[i]) res ++;
        }
        cout << res -1 << '\n';
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