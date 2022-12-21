#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int n, m;
const int dx[5] = {0, 0, 1, -1, 0} , dy[5] = {1, -1, 0, 0, 0};
bool check(vector<PII> &e, vector<vector<int>> &a) {
    for(PII u : e) {
        for(int i = 0; i < 5; i ++) {
            int x = u.first + dx[i], y = u.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m) {
                if(a[x][y] == 1) continue;
                bool ok = 0;
                for(int j = 0; j < 4; j ++) {
                    int xx = x + dx[j], yy = y + dy[j];
                    if(xx >= 0 && xx < n && yy >= 0 && yy < m) {
                        if(a[xx][yy] < a[x][y]) {
                            ok = 1;
                        }
                    }
                }
                if(!ok) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n ; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }
    vector<PII> bad;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(a[i][j] == 1) continue;
            bool ok = 0;
            for(int t = 0; t < 4; t ++) {
                int x = i + dx[t], y = j + dy[t];
                if(x >= 0 && x < n && y >= 0 && y < m)
                if(a[x][y] < a[i][j]) {
                    ok = 1;
                }
            }
            if(!ok) {
                bad.push_back({i, j});
            }
        }
    }
    if(bad.size() == 0) {
        cout << 0;
    } else if(bad.size() > 4) {
        cout << 2;
    } else {
        set<PII> s;
        int res = 0;
        for(int xl = 0; xl < bad.size(); xl ++) {
            for(int t = 0; t < 5; t ++) {
                int x = bad[xl].first + dx[t], y = bad[xl].second + dy[t];
                if(x >= 0 && x < n && y >= 0 && y < m) {
                    for(int r = 0; r < n; r ++) {
                        for(int c = 0; c < m; c ++) {
                            bad.push_back({r, c});
                            swap(a[r][c], a[x][y]);

                            if(check(bad, a)) {
                                int l = a[r][c], r = a[x][y];
                                if(l > r) swap(l, r);
                                if(s.find({l, r}) == s.end()) {
                                    res ++;
                                    s.insert({l, r});
                                }
                            }
                            swap(a[r][c], a[x][y]);
                            bad.pop_back();
                        }
                    }
                }
            }
        }
        if(res) {
            cout << "1 " << res;
        } else {
            cout << 2;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}