#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int> (n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> a[j][i];
        }
    }
    vector<vector<int>> b = a;
    sort(b.begin(), b.end());
    vector<bool> vis(m);
    int x = -1, y = - 1;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(j && b[j - 1][i] > b[j][i]) {
                cout << -1 << '\n';
                return ;
            }
            if(a[j][i] != b[j][i]) {
                if(vis[j]) continue;
                if(x == -1) {
                    x = j;
                } else if(y == -1) {
                    y = j;
                } else {
                    cout << -1 << '\n';
                    return ;
                }
                vis[j] = 1;
            }
        }
    }
    if(x == - 1) {
        cout << "1 1\n";
    } else {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
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