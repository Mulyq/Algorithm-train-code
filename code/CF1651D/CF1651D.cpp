#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
PII q[MAXN << 2];
int hh = 0, tt = - 1;
void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    set<PII> S;
    map<PII, PII> mp, res;
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first >> a[i].second;
        S.insert(a[i]);
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < 4; j ++) {
            int nx = a[i].first + dx[j], ny = a[i].second + dy[j];
            if(S.count({nx, ny})) {
                continue;
            }
            res[{a[i].first, a[i].second}] = {nx, ny};
            q[++ tt] = a[i];
            break;
        }
    }
    while(tt + 1 != hh) {
        int x = q[hh].first, y = q[hh].second;
        hh ++;
        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!S.count({nx, ny}) || res.count({nx, ny})) {
                continue;
            }
            res[{nx, ny}] = res[{x, y}];
            q[++ tt] = {nx, ny};
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << res[a[i]].first << ' ' << res[a[i]].second << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}