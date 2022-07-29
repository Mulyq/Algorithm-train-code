#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

    void solve() {
        int n, m;
        string s;
        cin >> n >> m >> s;
        vector<int> cres(n * m), rres(n * m);
        vector<int> row(n), col(m);
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == '1') {
                if(col[i % m] == 0) {
                    col[i % m] = 1;
                    cres[i] ++;
                }
            }
        }
        for(int i = 1; i < n * m; i ++ ) {
            cres[i] += cres[i - 1];
        }
        int l = -INF;
        for(int i = 0; i < s.size(); i ++) {
            if(i - m >= 0) {
                rres[i] = rres[i - m];
            }
            if(s[i] == '1') {
                l = i;
            }
            if(i - l < m) {
                rres[i] ++;
            }
        }
        for(int i = 0; i < n * m; i ++) {
            cout << rres[i] + cres[i]  << ' ';
        }
        cout << '\n';
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