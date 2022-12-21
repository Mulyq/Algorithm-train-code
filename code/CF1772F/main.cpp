#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct PC {
    vector<vector<char>> p;
    int xl;
    vector<PII> s;
};
bool cmp (PC a, PC b) {
    if(a.s.size() != b.s.size())
        return a.s.size() > b.s.size();
    return a.xl < b.xl;
};
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, w;
    cin >> n >> m >> w;
    vector<PC> pc(w + 1);
    for(int i = 0; i <= w; i ++) {
        pc[i].p.resize(n, vector<char> (m));
        pc[i].xl = i + 1;
    }
    for(int i = 0; i <= w; i ++) {
        for(int j = 0; j < n; j ++) {
            for(int k = 0; k < m; k ++) {
                cin >> pc[i].p[j][k];
            }
        }
    }
    for(int i = 0; i <= w; i ++) {
        for(int j = 1; j < n - 1; j ++) {
            for(int k = 1; k < m - 1; k ++) {
                bool ok = 1;
                for(int x = 0; x < 4; x ++) {
                    if(!((pc[i].p[j][k] - '0') ^ (pc[i].p[j + dx[x]][k + dy[x]] - '0'))) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    pc[i].s.push_back({j, k});
                }
            }
        }
    }
    sort(pc.begin(), pc.end(), cmp);
    cout << pc[0].xl << '\n';
    vector<array<int, 3>> res;
    for(int i = 1; i < pc.size(); i ++) {
        vector<vector<char>> *a = &pc[i - 1].p;
        vector<vector<char>> *b = &pc[i].p;
        for(int j = 0; j < n; j ++) {
            for(int k = 0; k < m; k ++) {
                if((*a)[j][k] != (*b)[j][k]) {
                    res.push_back({1, j + 1, k + 1});
                }
            }
        }
        res.push_back({2, pc[i].xl, 0});
    }
    cout << res.size() << '\n';
    for(auto &[op, x, y] : res) {
        if(op == 1) {
            cout << op << ' ' << x << ' ' << y << '\n';
        } else {
            cout << op << ' ' << x << '\n';
        }
    }
}