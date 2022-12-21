#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<ll, ll> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    ll n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<ll> len;
    len.push_back(s.size());
    vector<PII> seg;
    for(int i = 0; i < c; i ++) {
        ll l, r;
        cin >> l >> r;
        len.push_back(r - l + 1);
        seg.push_back({l, r});
    }
    for(int i = 1; i <= c; i ++) {
        len[i] += len[i - 1];
    }
    while(q --) {
        ll k;
        cin >> k;
        int xl = 0;
        while(len[xl] < k) xl ++;
        while(k > s.size()) {
            k = seg[xl - 1].second - (len[xl] - k);
            while(len[xl] >= k) xl --;
            xl ++;
        }
        cout << s[k - 1] << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}