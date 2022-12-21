#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
void solve() {
    ll all = 0;
    int n;
    map<ll,int> mp;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        ll x;
        cin >> x;
        mp[x] ++;
        all += x;
    }
    int cnt = 0;
    queue<ll> q;
    q.push(all);
    while (cnt < n - 1) {
        ll x = q.front();
        q.pop();
        if(mp[x]) {
            mp[x] --;
            continue;
        } else {
            cnt ++;
            ll a, b;
            if(x % 2 == 1) {
                a = x / 2;
                b = x / 2 + 1;
            } else {
                a = b = x / 2;
            }
            q.push(a);
            q.push(b);
        }
    }
    while (q.size()) {
        ll x = q.front();
        q.pop();
        if(mp[x] == 0) {
            cout <<  "No\n";
            return ;
        } else {
            mp[x] --;
        }
    }
    cout << "Yes\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}