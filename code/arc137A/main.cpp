#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
const int INF = 0x3f3f3f3f;
ll l, r;
ll res = 0;
void bfs(ll l, ll r) {
    queue<PII> q;
    q.push({l, r});
    while (q.size()) {
        PII u = q.front();
        q.pop();
        ll x = u.first, y = u.second;
        if(__gcd(x, y) == 1) {
            cout << y - x;
            return ;
        } else {
            q.push({x + 1, y});
            q.push({x, y - 1});
        }
        
    }
    
}
void solve() {
    cin >> l >> r;
    bfs(l ,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}