#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
vector<int> e[MAXN];
vector<int> temp;
vector<vector<int>> res;
void dfs(int r, int p) {
    temp.push_back(r);
    for(int v : e[r]) if(v != p) {
        dfs(v, r);
    }
    if(temp.size())
        res.push_back(temp);
    temp.clear();
}
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        e[i].clear();
        res.clear();
    }
    int R = 0 ;
    for(int i = 0; i < n; i ++) {
        int f;
        cin >> f;
        f --;
        if(f != i) {
            e[f].push_back(i);
        } else {
            R = f;
        }
    }
    dfs(R, R);
    cout << res.size() << '\n';
    for(auto L : res) {
        cout << L.size() << '\n';
        for(auto x : L) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
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