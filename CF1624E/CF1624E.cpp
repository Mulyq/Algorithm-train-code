#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int n, m;
void solve() {
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    map<string, pair<PII,int>> mp;
    for(int i = 0; i < n; i ++) {
        string temp = s[i];
        for(int j = 0; j < m - 1; j ++) {
            mp[temp.substr(j, 2)] = {{j, j + 1}, i};
            if(j + 2 < m) {
                mp[temp.substr(j, 3)] = {{j, j + 2}, i};
            }
        }
    }
    vector<bool> ok(m + 1);
    vector<int> tt(m + 1);
    string ss;
    cin >> ss;
    ok[0] = 1;
    for(int i = 0; i < m - 1; i ++) {
        if(!ok[i]) continue;
        if(mp.find(ss.substr(i, 2)) != mp.end()) {
            ok[i + 2] = 1;
            tt[i + 2] = 2;
        }
        if(i + 2 < m) {
            if(mp.find(ss.substr(i, 3)) != mp.end()) {
                ok[i + 3] = 1;
                tt[i + 3] = 3;
            }
        }
    }
    vector<pair<PII,int>> res;
    if(!ok[m]) {
        cout << -1 << '\n';
    } else {
        int n = m;
        while(n != 0) {
            res.push_back(mp[ss.substr(n - tt[n], tt[n])]);
            n -= tt[n];
        }
        reverse(res.begin(), res.end());
        cout << res.size() << '\n';
        for(auto x : res) {
            cout << x.first.first + 1 << ' ' << x.first.second + 1 << ' ' << x.second + 1 << '\n';
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