#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    string s;
    int n;
    cin >> s >> n;
    int len = s.size();
    vector<string> ans(n);
    for(int i = 0; i < n; i ++) {
        cin >> ans[i];
    }
    vector<pair<int,string>> rec;
    for(int i = 0; i < n; i ++) {
        if(ans[i].size() == len) {
            int val = 0;
            for(int j = 0; j < len; j ++) {
                if(ans[i][j] == s[j]) {
                    val ++;
                }
            }
            rec.push_back({-val, ans[i]});
        }
    }
    sort(rec.begin(), rec.end());
    int v = 0;
    if(rec.size())
        v = rec[0].first;
    if(v) {
        for(auto it : rec) {
            if(it.first != v) break;
            cout << it.second << '\n';
        }
    } else {
        sort(ans.begin(), ans.end());
        for(auto it : ans) {
            cout << it << '\n'; 
        }
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}