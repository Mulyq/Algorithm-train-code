#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> all;
    while(n) {
        all.push_back(n & -n);
        n -= n & -n;
    }
    vector<ll> res;
    for(int i = 0; i < (1 << all.size()); i ++) {
        ll r = 0;
        for(int j = 0; j < all.size(); j ++) {
            if(i & (1 << j)) r += all[j];
        }
        res.push_back(r);
    }
    sort(res.begin(), res.end());
    for(ll v : res) {
        cout << v << '\n';
    }
}