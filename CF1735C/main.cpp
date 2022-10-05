#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string t, s;
    cin >> t;
    vector<int> pre(26, -1);
    vector<int> nex(26, -1);
    vector<bool> vis(26);
    for(int i = 0; i < n; i ++) {
        int to = t[i] - 'a';
        if(pre[to] == -1) {
            for(int j = 0; j < 26; j ++) {
                if(j != to && nex[j] == -1) {
                    bool ok = 1;
                    int temp = pre[j];
                    int c = 1;
                    while(temp != -1) {
                        c ++;
                        if(temp == to) {
                            ok = 0;
                            break;
                        }
                        temp = pre[temp];
                    }
                    if(ok || (!ok && c == 26)) {
                        pre[to] = j;
                        nex[j] = to;
                        break;
                    }
                }
            }
        }
        s.push_back('a' + pre[to]);
    }
    cout << s << '\n';
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