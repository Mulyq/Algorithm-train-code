#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
vector<int> res;
vector<bool> vis, visl, visr;
int n;
int sum;
void dfs(int x) {
    if(x == n + 1) {
        sum ++;
        if(sum <= 3) {
            for(auto it :res) {
                cout << it << ' ';
            }
            cout << '\n';
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && !visl[x + i - 1] && !visr[i - x + 1 + n]) {
            res.push_back(i);
            visl[x + i - 1] = visr[i - x + 1 + n] = vis[i] = 1;
            dfs(x + 1);
            res.pop_back();
            visl[x + i - 1] = visr[i - x + 1 + n] = vis[i] = 0;
        }
    }
}
void solve() {
    cin >> n;
    vis.resize(n + 1);
    visl.resize(2 * n + 2);
    visr.resize(2 * n + 2);
    dfs(1);
    cout << sum << '\n';
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