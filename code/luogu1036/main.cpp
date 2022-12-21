#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int res, cnt, now;
bool isprime(int x) {
    if(x == 1) {
        return 0;
    }
    for(int i = 2; i <= x / i; i ++) {
        if(x % i == 0) {
            return 0;
        }
    }
    return 1;
}
void dfs(vector<int> a, int k, int x) {
    if(cnt == k) {
        if(isprime(now)) {
            res ++;
        }
        return ;
    }
    if(x == a.size()) {
        return ;
    }
    dfs(a, k, x + 1);
    cnt ++, now += a[x];
    dfs(a, k, x + 1);
    cnt --, now -= a[x];
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    dfs(a,k , 0);
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