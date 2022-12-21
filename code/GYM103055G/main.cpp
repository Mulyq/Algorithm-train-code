#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int dx[6] = {-1, 0, 1, 1, 0, -1}, dy[6] = {1, 1 ,0 ,-1 ,-1 ,0};
struct DSU {
    int N;
    vector<int> pr, wall;
    DSU(int n) : N(n) {
        pr.resize(N + 1);
        wall.resize(N + 1);
        for(int i  = 0; i <= N; i ++) {
            pr[i] = i;
            wall[i] = 6;
        }
    }
    int root(int x ) {
        return pr[x] == x ? x : pr[x] = root(pr[x]);
    }
    bool unite(int x, int y) {
        int X = root(x), Y = root(y);
        if(X == Y) return 1;
        pr[X] = Y;
        wall[Y] += wall[X];
        return 0;
    }
};

void solve() {
    int q;
    cin >> q;
    map<PII, int> mp;
    DSU dsu(500010);
    int idx = 0;
    while(q --) {
        int x, y;
        int op;
        cin >> op >> x >> y;
        if(op == 1) {
            vector<PII> temp;
            for(int i = 0; i < 6; i ++) {
                int X = x + dx[i];
                int Y = y + dy[i];
                if(mp.find({X, Y}) != mp.end()) {
                    temp.push_back({X, Y});
                    dsu.wall[idx] --;
                    dsu.wall[dsu.root(mp[{X, Y}])] --;
                } 
            }
            for(auto it : temp) {
                dsu.unite(idx, mp[{it.first, it.second}]);
            }
            mp[{x, y}] = idx ++;
        } else {
            cout << dsu.wall[dsu.root(mp[{x, y}])] << '\n';
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