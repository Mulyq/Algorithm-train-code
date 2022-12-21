#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> t = a;
    for(int i = 0; i < n; i ++) {
        t[i] -= i;
    }
    vector<int> s(1, 1);
    vector<ll> v(1, t[0]);
    for(int i = 1; i < n; i ++) {
        if(t[i] <= v.back()) {
            s.back() ++;
        } else {
            v.push_back(t[i]);
            s.push_back(1);
        }
    }
    v.push_back(1e18);
    for(int i = 1; i < s.size(); i ++) {
        s[i] += s[i - 1];
    }
    ll res = 0;
    while(1) {
        int i = upper_bound(v.begin(), v.end(), x) - v.begin();
        if(!i) {
            cout << -1 << '\n';
            return ;
        }
        if(x + s[i - 1] >= y) {
            cout << res + y - x << '\n';
            return ;
        } else {
            int add = 2 * s[i - 1] - n;
            if(add <= 0) {
                cout << -1 << '\n';
                return;
            } else {
                ll teg = min(y - s[i - 1], v[i]);
                ll cnt = (teg - x + add - 1) / add;
                res += cnt * n;
                x += cnt * add;
            }
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
}