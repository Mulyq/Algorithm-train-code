#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int l = 0, r = 1e9;
    while(r - l > 1) {
        int m = 1ll * l + r >> 1;
        ll c = 0;
        for(int i = 0; i < n; i ++) {
            c += (a[i] - 1) / m;
        }
        if(c > k) l = m;
        else r = m;
    }
    cout << r << '\n';
}