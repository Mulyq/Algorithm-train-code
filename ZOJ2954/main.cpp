#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int step = 0;
    int n, m;
    cin >> n >> m;
    vector<PII> op(m);
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        op[i] = {x, y};
    }
    vector<vector<int> > sum(3);
    for(int i = 1; i <= n; i ++) {
        sum[0].push_back(n - i + 1);
    }
    for(int i = 0; i < m; i ++) {
        int x = op[i].first, y = op[i].second;
        x --, y --;
        step ++;
        if(sum[x].empty()) {
            cout << -step << '\n';
            return ;
        }
        if(sum[y].size()) {
            if(sum[x].back() > sum[y].back()) {
                cout << -step << '\n';
                return;
            } else {
                sum[y].push_back(sum[x].back());
                sum[x].pop_back();
            }
        } else {
            sum[y].push_back(sum[x].back());
            sum[x].pop_back();
        }
        if(sum[2].size() == n) {
            cout << step << '\n';
            return ;
        }
    }
    cout << 0 << '\n';
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