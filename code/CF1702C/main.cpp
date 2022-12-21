#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, PII> mp;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(mp.find(x) == mp.end()) {
            mp[x].first = i, mp[x].second = i;
        } else {
            mp[x].second = i;
        }
    }
    while(q --) {
        int a, b;
        cin >> a >> b;
        if(mp.find(a) != mp.end() && mp.find(b) != mp.end() && mp[a].first < mp[b].second) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
    return 0;
}