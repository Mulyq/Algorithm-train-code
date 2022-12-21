#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    vector<vector<int>> b(n + 1, vector<int> (m + 1));
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x0 = i - 1, y0 = j - 1;
            for(int len = 1; x0 + len <= n && y0 + len <= m; len ++) {
                int w = b[x0 + len][y0 + len] - b[x0 + len][y0] - b[x0][y0 + len] + b[x0][y0];
                if(w == len * len) {
                    res = max(res, len);
                }
            }
        }
    }
    cout << res;
    return 0;
}