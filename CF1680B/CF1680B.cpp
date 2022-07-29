#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            char x;
            cin >> x;
            if(x == 'R')  {
                a[i][j] ++;
                cnt ++;
            }
        }
    }
    for(int i = n - 1; i >= 0; i --) {
        for(int j = m - 1; j >= 0; j --) {
            b[i][j] = a[i][j] + b[i + 1][j] + b[i][j + 1] - b[i + 1][j + 1];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(a[i][j] == 1 && b[i][j] == cnt) {
                cout << "YES\n";
                return ;
            }
        }
    }
    cout << "NO\n";

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