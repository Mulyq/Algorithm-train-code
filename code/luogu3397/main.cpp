#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int> (n + 2));
    for(int i = 0; i < m; i ++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1] ++, a[x2 + 1][y2 + 1] ++;
        a[x1][y2 + 1] --, a[x2 + 1][y1] --;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
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