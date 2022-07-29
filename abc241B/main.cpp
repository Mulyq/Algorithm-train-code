#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    map<int, int> mp;
    for(int i = 0; i < n; i ++) {
        int temp;
        cin >> temp;
        mp[temp] ++;
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
    }
    for(int i = 0; i < m; i ++)  {
        if(mp[b[i]]) {
            mp[b[i]] --;
        } else{
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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