#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j ++) {
            v[i][j] = s[j] - '0';
        }
    }
    struct OP {
        int i, j, l, r, p;
    };
    int q;
    cin >> q;
    vector<OP> op(q);
    for(auto &[i, j, l, r, p] : op) {
        cin >> i >> j >> l >> r >> p;
    }
    int res = 0;
    for(int i = 0; i < m; i ++) {
        int c = 1;
        for(int j = 0; j < n; j ++) {
            c &= v[j][i];
        }
        res += c;
    }
    cout << res << '\n';
}