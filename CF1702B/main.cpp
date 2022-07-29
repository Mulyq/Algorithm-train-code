#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    string s;
    cin >> s;
    vector<bool> vis(26);
    int cnt = 0;
    int dd = 1;
    int i = 0;
    while(i < s.size()) {
        int x = s[i] - 'a';
        if(!vis[x]) {
            vis[x] = 1;
            cnt ++;
        }
        i ++;
        if(cnt == 4) {
            for(int i = 0; i < 26; i ++) {
                vis[i] = 0;
            }
            cnt = 1;
            dd ++;
            vis[x] = 1;
        }
    }
    cout << dd << '\n';
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