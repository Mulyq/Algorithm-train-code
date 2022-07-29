#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    int p = 0;
    for(auto it : mp) {
        p = max(p, it.second);
    }
    int r = n - p;
    int res = 0;
    while (r > 0) {
        res ++;
        res += min(r, p);
        r -= p;
        p *= 2;
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