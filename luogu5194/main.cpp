#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int n, c;
vector<ll> a, all;
ll res = 0;
void dfs(int x, ll sum) {
    if(x == -1) {
        res = max(res, sum);
        return;
    }
    if(sum + a[x] <= c) {
        dfs(x - 1, sum + a[x]);
    }
    if(x && all[x - 1] + sum <= c) {
        res = max(res, all[x - 1] + sum);
        return ;
    }
    dfs(x - 1, sum);
}
void solve() { 
    cin >> n >> c;
    a.resize(n);
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    all.resize(n);
    for(int i = 0; i < n; i ++) {
        if(!i) all[i] = a[i];
        else all[i] = all[i - 1] + a[i];
    }
    while (a.back() > c) a.pop_back();
    dfs(a.size() - 1, 0);
    cout << res << '\n';
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