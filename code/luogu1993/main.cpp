#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 5e3 + 10;
vector<vector<PII>> e(N);
vector<int> dis(N, INF);
int n, m;
bool belm() {
    dis[1] = 0;
    bool ok = 0;
    for(int i = 0; i < n; i ++) {
        ok = 0;
        for(int j = 1; j <= n; j ++) {
            for(auto it : e[j]) {
                if(dis[it.first] > dis[j] + it.second) {
                    ok = 1;
                    dis[it.first] = dis[j] + it.second;
                }
            }
        }
    }
    return ok;
}
void solve() {
    cin >> n >> m;
    map<int, int> mp;
    int idx = 1;
    for(int i = 0; i < m; i ++) {
        int t;
        cin >> t;
        if(t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            if(!mp[a]) mp[a] = idx ++;
            if(!mp[b]) mp[b] = idx ++; 
            a = mp[a], b = mp[b];
            e[a].push_back({b, -c});
        } else if(t == 2) {
            int a, b , c;
            cin >> a >> b >> c;
            if(!mp[a]) mp[a] = idx ++;
            if(!mp[b]) mp[b] = idx ++; 
            a = mp[a], b = mp[b];
            e[b].push_back({a, c});
        } else {
            int a, b;
            cin >> a >> b;
            if(!mp[a]) mp[a] = idx ++;
            if(!mp[b]) mp[b] = idx ++; 
            a = mp[a], b = mp[b];
            e[a].push_back({b, 0});
            e[b].push_back({a, 0});
        }
    }
    if(belm()) cout << "No\n";
    else cout << "Yes\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}