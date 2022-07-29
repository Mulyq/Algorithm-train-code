#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
// #include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
char a[110][110];
int n, m, res;
void dfs(int x, int y) {
    if(a[x][y] == '.' || x < 0 || x >= n || y < 0 || y >= m) return;
    a[x][y] = '.';
    const int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1}, dy[8] = {1, 0, -1, 0, -1, -1, 1, 1};
    for(int i = 0; i < 8; i ++) {
        dfs(x + dx[i], y + dy[i]);
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n;i ++) {
        for(int j = 0 ; j < m; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(a[i][j] == 'W') {
                dfs(i, j);
                res ++;
            }
        }
    }
    cout << res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}