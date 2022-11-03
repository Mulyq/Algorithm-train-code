#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 4e5 + 10, mod = 998244353;
int n, m;            //M, N分别表示左、右侧集合的元素数量
vector<vector<int>> G;
int p[MAXN];         //记录当前右侧元素所对应的左侧元素
bool vis[MAXN];      //记录右侧元素是否已被访问过
bool match(int i) {
    bool ok = 0;
    for(int v : G[i]) if(!vis[v]) {
        vis[v] = 1;
        if(!ok && (p[v] == 0 || match(p[v]))) {
            p[v] = i;
            ok = 1;
        }
        vis[v] = 0;
    }
    return ok;
}
int Hungarian() {
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(match(i)) {
            cnt ++;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    m = 4e5;
    G.resize(n + 1);
    for(int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        G[i].push_back(a);
        G[i].push_back(b);
    }
    cout << Hungarian() << '\n';
}