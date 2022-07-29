#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int> (m));
    for(int i = 0; i < n / 2; i ++) {
        for(int j = 0; j < m/ 2; j ++) {
            int r = 2 * i, c = 2 *j;
            if((i + j) % 2 == 0) {
                res[r + 1][c + 1] = res[r][c] = 1;
            } else {
                res[r][c + 1] = res[r + 1][c] = 1;
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cout << res[i][j] << ' '; 
        }
        cout << '\n';
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