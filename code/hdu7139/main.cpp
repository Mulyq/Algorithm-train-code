#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int n, m, k;
int xs, ys, xt, yt;
struct seg{
    int x1, y1, x2, y2;
};
seg S[20];
bool gra[40][40];
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool check() {
    queue<PII> q;
    vector<vector<bool>> vis(40, vector<bool> (40));
    q.push({xs, ys});
    vis[xs][ys] = 1;
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        if(x == xt && y == yt) {
            return 1;
        }
        q.pop();
        for(int i = 0; i < 4 ;i ++) {
            int X = x + dx[i], Y = y + dy[i];
            if(X >= 0 && X <= n && Y >= 0 && Y <= m && !vis[X][Y] && !gra[X][Y]) {
                q.push({X, Y});
                vis[X][Y] = 1;
            }
        }
    }
    return 0;
}
void solve() {
    cin >> n >> m >> k;
    (n *= 2) + 1;
    (m *= 2) + 1;
    cin >> xs >> ys >> xt >> yt;
    (xs *= 2) += 1;
    (ys *= 2) += 1;
    (xt *= 2) += 1;
    (yt *= 2) += 1;
    for(int i = 0; i < k; i ++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 *= 2;
        x2 *= 2;
        y1 *= 2;
        y2 *= 2;
        S[i] = {x1, y1, x2, y2};
    }
    int res = INF;
    for(int i = 0; i < (1 << k); i ++) {
        int temp = i;
        int w = 0;
        while(temp) {
            temp -= (temp & - temp);
            w ++;
        }
        w = k - w;
        if(w >= res) continue;
        temp = i;
        int c = k, xl = 0;
        while(temp) {
            if(temp & 1) {
                for(int x = S[xl].x1;x <= S[xl].x2; x ++) {
                    for(int y = S[xl].y1; y <= S[xl].y2; y ++) {
                        gra[x][y] |= 1;
                    }
                }
                c --;
            }
            xl ++;
            temp >>= 1;
        }
        if(check()) {
            res = min(res, c);
        }
        temp = i;
        xl = 0;
        while(temp) {
            if(temp & 1) {
                for(int x = S[xl].x1; x <= S[xl].x2; x ++) {
                    for(int y = S[xl].y1; y <= S[xl].y2; y ++) {
                        gra[x][y] &= 0;
                    }
                }
            }
            temp >>= 1;
            xl ++;
        }
    }
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