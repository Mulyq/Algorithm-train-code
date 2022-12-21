#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int n, ml, md;
vector<vector<PII> > e;
vector<int> dis;
bool belm() {
    dis.resize(n + 1, INF);
    bool ok = 0;
    dis[1] = 0;
    for(int i = 1; i <= n; i ++) {
        ok = 0;
        for(int j = 1; j <= n; j ++) {
            for(int k = 0; k < e[j].size(); k ++) {
                if(dis[e[j][k].first] > dis[j] + e[j][k].second) {
                    dis[e[j][k].first] = dis[j] + e[j][k].second;
                    ok = 1;
                }
            }
        }
    }
    return ok;
}
void solve() {
    cin >> n >> ml >> md;
    e.resize(n + 1);
    for(int i = 1; i < n; i ++) {
        e[i + 1].push_back(make_pair(i, 0));
    }
    for(int i = 0; i < ml; i ++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back(make_pair(v, w));
    }
    for(int i = 0; i < md; i ++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[v].push_back(make_pair(u, -w));
    }
    if(belm()) printf("-1\n");
    else if(dis[n] >= INF / 2) printf("-2\n");
    else printf("%d\n", dis[n]);
    
}
int main() {
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}