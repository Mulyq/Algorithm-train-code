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
const int INF = 0x3f3f3f3f, M = 1e4 + 10;
int n, m, r;
pair<int,pair<int,int> > e[5 * M];
vector<int> pr;
int root(int x) {
    return pr[x] == x ? x : pr[x] = root(pr[x]);
}
int Krusal() {
    ll res = 0;
    pr.resize(n + m + 1);
    for(int i = 0; i < n + m; i ++) {
        pr[i] = i;
    }
    for(int i = 0; i < r; i ++) {
        int u = e[i].second.first, v = e[i].second.second;
        int U = root(u), V = root(v);
        if(U != V) {
            res += e[i].first;
            pr[U] = V;
        }
    }
    return res;
}
void solve() {
    scanf("%d%d%d", &n, &m, &r);
    for(int i = 0; i < r; i ++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        e[i].first = -w;
        e[i].second = make_pair(x, n + y);
    }
    sort(e, e + r);
    printf("%d\n",(n + m) * 10000 + Krusal());
}
int main(){
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}