#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> a(2, vector<ll> (n));
    for(int i = 0; i < 2 ;i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }
    int c = 0;
    for(int i = 0; i < 2 ;i ++) {
        for(int j = 0; j < n; j ++) {
            int x;
            cin >> x;
            a[i][j] -= x;
            c += a[i][j];
        }
    }
    if(c) {
        cout << -1;
        return ;
    }
    ll res = 0;
    for(int i = 0; i < n; i ++) {
        if(a[0][i]) if((a[0][i] > 0 && a[1][i] < 0) || (a[0][i] < 0 && a[1][i] > 0)) {
            ll x = min(abs(a[1][i]), abs(a[0][i]));
            if(a[0][i] > 0 && a[1][i] < 0) {
                a[0][i] -= x;
                a[1][i] += x;
            } else {
                a[0][i] += x;
                a[1][i] -= x;
            }
            res += x;
        }
        res += abs(a[0][i]) + abs(a[1][i]);
        if(i != n -1) {
            a[0][i + 1] += a[0][i];
            a[1][i + 1] += a[1][i];
        }
    }
    cout << res << '\n';
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}