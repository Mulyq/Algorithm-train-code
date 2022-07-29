#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 5e3 + 3;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(N, vector<int>(N));
    for(int i = 0; i < n; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        x ++ ,y ++;
        a[x][y] += w;
    }
    for(int i = 1; i <= N - 1; i ++) {
        for(int j = 1; j <= N - 2; j ++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int res = 0;
    for(int i = 1; i <= N - 1 - m; i ++) {
        for(int j = 1; j <= N - 1 - m; j ++) {
            int sum = a[i + m - 1][j + m - 1] - a[i - 1][j + m - 1] - a[i + m - 1][j - 1] + a[i - 1][j - 1];
            res = max(res, sum);
        }
    }
    cout << res << '\n';
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