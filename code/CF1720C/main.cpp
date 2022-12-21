#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
void solve() {
    int n, m;
    cin >> n >> m;
    int res = 0;
    vector<vector<char>> G(n, vector<char> (m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> G[i][j];
            res += G[i][j] - '0';
        }
    }
    int mm = INF;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            int cc = G[i][j] - '0', A = - 1, B = -1, C = - 1, D = - 1;
            if(i - 1 >= 0) A = G[i - 1][j] - '0';
            if(j - 1 >= 0) B = G[i][j - 1] - '0';
            if(i + 1  < n) C = G[i + 1][j] - '0';
            if(j + 1  < m) D = G[i][j + 1] - '0';
            if(A >= 0 && B >= 0) if(A + B + cc > 0) mm = min(mm, A + B + cc);
            if(A >= 0 && D >= 0) if(A + D + cc > 0) mm = min(mm, A + D + cc);
            if(C >= 0 && B >= 0) if(C + B + cc > 0) mm = min(mm, C + B + cc);
            if(D >= 0 && C >= 0) if(D + C + cc > 0) mm = min(mm, D + C + cc);
        }
    }
    if(mm != INF)
        res -= mm - 1;
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