#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if(k & 1) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
    } else {
        struct dir {
            int up, dn, le, ri;
            dir() {
                up = dn = le = ri = INF;
            }
        };
        vector<vector<dir>> G(n, vector<dir> (m));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m - 1; j ++) {
                int x;
                cin >> x;
                G[i][j].ri = G[i][j + 1].le = x;
            }
        }
        for(int i = 0; i < n - 1; i ++) {
            for(int j = 0; j < m ;j ++) {
                int x;
                cin >> x;
                G[i][j].dn = G[i + 1][j].up = x;
            }
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                vector<vector<vector<int>>> dp (k + 1, vector<vector<int>> (k + 1, vector<int> (k + 1, INF)));
                struct node {
                    int x, y, d, c;
                };
                queue<node> q;
                q.push({i, j, 0, 0});
                dp[k / 2][k / 2][0] = 0;
                int res = INF;
                while(q.size()) {
                    int x = q.front().x, y = q.front().y, d = q.front().d, c = q.front().c;
                    q.pop();
                    if(c == k / 2) {
                        res = min(res, d);
                        continue;
                    }
                    if(x - 1 >= 0 && x - 1 < n && dp[k / 2 + (x - 1) - i][k / 2 + y - j][c + 1] > d + G[x][y].up) {
                        dp[k / 2 + (x - 1) - i][k / 2 + y - j][c + 1] = d + G[x][y].up;
                        q.push({x - 1, y, d + G[x][y].up, c + 1});
                    }
                    if(x + 1 >= 0 && x + 1 < n && dp[k / 2 + (x + 1) - i][k / 2 + y - j][c + 1] > d + G[x][y].dn) {
                        dp[k / 2 + (x + 1) - i][k / 2 + y - j][c + 1] = d + G[x][y].dn;
                        q.push({x + 1, y, d + G[x][y].dn, c + 1});
                    }
                    if(y - 1 >= 0 && y - 1 < m && dp[k / 2 + x - i][k / 2 + (y - 1) - j][c + 1] > d + G[x][y].le) {
                        dp[k / 2 + x - i][k / 2 + (y - 1) - j][c + 1] = d + G[x][y].le;
                        q.push({x, y - 1, d + G[x][y].le, c + 1});
                    }
                    if(y + 1 >= 0 && y + 1 < m && dp[k / 2 + x - i][k / 2 + (y + 1) - j][c + 1] > d + G[x][y].ri) {
                        dp[k / 2 + x - i][k / 2 + (y + 1) - j][c + 1] = d + G[x][y].ri;
                        q.push({x, y + 1, d + G[x][y].ri, c + 1});
                    }
                }
                cout << res * 2 << ' ';
            }
            cout << '\n';
        }
    }

}