#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> ee(26);
    for(int i = 0; i < n; i ++) {
        ee[s[i] - 'a'].push_back(i);
    }
    queue<int> q;
    vector<bool> vis(26);
    for(int i = 0; i < 26; i ++) {
        int mm = -1;
        for(int j = 0; j < 26; j ++) {
            if(!vis[j] && ee[j].size()) {
                if(mm == - 1) {
                    mm = j;
                } else {
                    if(ee[j][0] < ee[mm][0]) {
                        mm = j;
                    }
                }
            }
        }
        if(mm != -1) {
            vis[mm] = 1;
            q.push(mm);
        }
    }
    int nn = 0;
    for(int i = 0; i < 26; i ++) {
        vis[i] = 0;
    }
    int mm = 0;
    while(q.size()) {
        int tt = q.front();
        if(k >= tt) {
            q.pop();
            nn = tt;
            mm = max(mm, nn);
            vis[nn] = 1;
        } else {
            break;
        }
    }
    k -= mm;
    string res = s;
    if(q.size()) {
        int tt = q.front();
        char x = s[ee[tt][0]] - k;
        for(int i = x - 'a'; i <= tt; i ++) {
            for(auto v : ee[i]) {
                res[v] = x;
            }
        }
    }
    for(int i = 0; i <= mm; i ++) {
        for(auto v : ee[i]) {
            res[v] = 'a';
        }
    }
    std::cout << res << '\n';
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