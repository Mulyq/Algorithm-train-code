#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    vector<PII> B;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> e(n, vector<char> (m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> e[i][j];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(e[i][j] == 'B') {
                while(B.size() < 4) {
                    B.push_back({i, j});
                }
                if(i + j < B[0].first + B[0].second) {
                    B[0] = {i, j};
                }
                if(i + j > B[1].first + B[1].second) {
                    B[1] = {i, j};
                }
                if(i - j > B[2].first - B[2].second) {
                    B[2] = {i, j};
                }
                if(i - j < B[3].first - B[3].second) {
                    B[3] = {i, j};
                }
            }
        }
    }
    int maxdis = INF;
    int resx = 0, resy = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            int dis = 0;
            for(auto it : B) {
                dis = max(dis, abs(it.first - i) + abs(it.second - j));
            }
            if(dis < maxdis) {
                maxdis = dis;
                resx = i, resy = j;
            }
        }
    }
    cout << resx + 1 << ' ' << resy + 1 << '\n';
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