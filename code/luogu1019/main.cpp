#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int n;
vector<string> str;
vector<int> cnt;
int res = 1;
void dfs(string now, int len) {
    for(int i = 0; i < str.size() - 1; i ++) {
        if(cnt[i] == 2) continue;
        int minlen = 40;
        for(int k = 1; k < now.size(); k ++) {
            int j = k;
            int l = 0;
            for(; j < now.size() && l < str[i].size(); j ++) {
                if(now[j] != str[i][l ++]) {
                    break;
                }
            }
            if(j == now.size() && l != str[i].size()) {
                minlen = min(minlen, (int)now.size() - k);
            }
        }
        if(minlen != 40) {
            cnt[i] ++;
            res = max(res, len + (int)str[i].size() - minlen);
            dfs(str[i], len + str[i].size() - minlen);
            cnt[i] --;
        }
    }
}
void solve() {
    cin >> n;
    str.resize(n + 1);
    cnt.resize(n + 1);
    for(int i = 0; i <= n; i ++) {
        cin >> str[i];
    }
    str[n] = ' ' + str[n];
    dfs(str[n], 1);
    cout << res << '\n';
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