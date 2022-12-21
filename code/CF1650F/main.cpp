#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    struct node {
        int t, p, idx;
    };
    vector<vector<node>> op(n);
    for(int i = 0; i < m; i ++) {
        int e, t, p;
        cin >> e >> t >> p;
        e --;
        op[e].push_back({t, p, i + 1});
    }
    vector<int> res;
    int cur = 0;
    for(int i = 0; i < n; i ++) {
        int N = op[i].size();
        vector<vector<int>> dp(N + 1, vector<int> (101, 1e9 + 1));
        dp[0][0] = 0;
        for(int j = 0; j < N; j ++) {
            dp[j + 1] = dp[j];
            for(int k = 0; k <= 100; k ++) {
                int nk = min(100, k + op[i][j].p);
                dp[j + 1][nk] = min(dp[j + 1][nk], dp[j][k] + op[i][j].t);
            }
        }
        cur += dp[N][100];
        if(cur > a[i]) {
            cout << "-1\n";  
            return ;
        }
        int nd = 100;
        for(int j = N - 1; j >= 0; j --) {
            if(dp[j + 1][nd] == dp[j][nd]) {
                continue;
            }
            res.push_back(op[i][j].idx);
            for(int k = 0; k <= 100; k ++) {
                int nk = min(100, k + op[i][j].p);
                if(nk == nd && dp[j][k] + op[i][j].t == dp[j + 1][nk]) {
                    nd = k;
                    break;
                }
            }
        }
    }
    cout << res.size() << '\n';
    for(auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}