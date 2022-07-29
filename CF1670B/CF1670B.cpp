#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int k;
    cin >> k;
    vector<int> sp(26);
    for(int i = 0; i < k; i ++ ) {
        char x;
        cin >> x;
        sp[x - 'a'] = 1;
    }
    int cnt = 0;
    int res = 0;
    for(int i = 0; i < n; i ++) {
        if(!sp[s[i] - 'a']) {
            cnt ++;
        } else {
            res = max(res, cnt);
            cnt = 1;
        }
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