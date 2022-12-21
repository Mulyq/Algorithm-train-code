#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 5e2 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    vector<pair<PII, int>> p(n + 1);
    for(int i = 1; i <= n; i ++) {
        if(b[i])
            p[i] = {{i / b[i], i / (b[i] + 1) + 1}, i};
        else
            p[i] = {{n, i + 1}, i};
    }
    vector<vector<pair<PII,int>>> e(n + 1);
    for(int i = 1; i <= n; i ++) {
        e[p[i].first.second].push_back(p[i]);
    }
    set<pair<PII, int>> S;
    vector<int> res(n + 1);
    for(int i = 1; i <= n; i ++) {
        for(auto x : e[i]) {
            S.insert(x);
        }
        auto it = S.begin();
        res[(*it).second] = i;
        S.erase(it);
    }
    for(int i = 1; i <= n; i ++) {
        cout << res[i] << ' ';
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