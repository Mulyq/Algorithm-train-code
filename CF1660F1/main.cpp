#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> b(n + 1);
    int cnt = 0;
    int res = 0;
    for(int i = 0 ; i < n; i ++) {
        if(s[i] == '+') cnt ++;
        else cnt --;
        b[i + 1] = cnt;
        for(int j = 0; j <= i; j ++) {
            if(b[j] >= b[i + 1] && (b[j] - b[i + 1]) % 3 == 0) {
                res ++;
            }
        }
    }
    // for(int i = 0; i <= n; i ++) {
    //     cout << b[i] << ' ';
    // }
    cout << '\n';
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