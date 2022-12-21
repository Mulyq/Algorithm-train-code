#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
vector<vector<PII>> e;
vector<int> dis;
int n, m;
bool belm() {
    dis.resize(n  + 1, INF);
    dis[1] = 0;
    bool ok;
    for(int i = 0; i  < n; i ++) {
        ok = 0;
        for(int j = 1; j <= n; j ++) {
            for(auto it : e[j]) {
                if(dis[it.first] > dis[j] + it.second) {
                    dis[it.first] = dis[j] + it.second;
                    ok = 1;
                }
            }
        }
    }
    return ok;
}
void solve() {
    cin >> n >> m;
    e.resize(n + 1);
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[v].push_back({u, w});
    }
    if(belm()) {
        cout << "NO"; 
    } else {
        for(int i = 1; i <= n; i ++) {
            cout << dis[i] <<' ';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}