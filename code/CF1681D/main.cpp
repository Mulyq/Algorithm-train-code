#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

void solve() {
    int n;
    ll x;
    map<ll, int> mp;
    cin >> n >> x;
    queue<ll> q;
    mp[x] = 0;
    q.push(x);
    while(q.size()) {
        ll num = q.front();
        q.pop();
        string s = to_string(num);
        if(s.size() == n) {
            cout << mp[num] << '\n';
            return ;
        }
        for(auto t : s) {
            if(t > '1') {
                ll w = num * (t - '0');
                if(mp.find(w) == mp.end()) {
                    mp[w] = mp[num] + 1;
                    q.push(w);
                }
            }
        }
    }
    cout << "-1\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}