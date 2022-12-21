#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int n, m, p, a, b;
int t[10];
int e[33][33];
double dp[1 << 8][33];
int solve() {
    while(~scanf("%d%d%d%d%d",&n, &m, &p, &a, &b)) {
        double res = 1e18;
        a --, b --;
        memset(e, 0x3f, sizeof e);
        if(m == 0 && n == 0) break; 
        for(int i = 0; i < (1 << n); i ++) {
            fill(dp[i], dp[i] + m, 1e18);
        }
        dp[(1 << n) - 1][a] = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &t[i]);
        }
        for(int i = 0; i < p; i ++) {
            int u, v, val;
            scanf("%d%d%d", &u, &v, &val);
            v --, u --;
            e[v][u] = e[u][v] = min(e[u][v], val);
        }
        for(int S = (1 << n) - 1; S >= 0; S --) {
            res = min(res, dp[S][b]);
            for(int i = 0; i < n; i ++) {
                if((S >> i) & 1) {
                    for(int form = 0; form < m; form ++) {
                        for(int to = 0; to < m; to ++) {
                            dp[S - (1 << i)][to]= min(dp[S - (1 << i)][to], dp[S][form] + 1.0 * e[form][to] / t[i]);          
                        }
                    }
                }
            }
        }
        if(res >= 1e7) {
            printf("Impossible\n");
        } else {
            printf("%.3f\n", res);
        }
    }
    return 0;
}

int main () {
    solve();
}