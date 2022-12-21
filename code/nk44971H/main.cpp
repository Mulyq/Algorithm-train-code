#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct Ary {
    vector<int> a;
    Ary(int n) {
        a.resize(n);
    }
    bool operator < (const Ary & x) const {
        for(int i = 0; i < a.size(); i ++) {
            if(a[i] != x.a[i]) {
                return a[i] < x.a[i];
            }
        }
        return 0;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &i : a) {
        cin >> i;
    }
    map<Ary, int> mp;
    for(int i = 0; i < m; i ++) {
        Ary x(n);
        for(int j = 0 ; j < n; j ++) {
            cin >> x.a[j];
        }
        mp[x] ++;
    }
    ll res = 0;
    for(auto i : mp) {
        res += i.second * (i.second - 1) / 2;
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