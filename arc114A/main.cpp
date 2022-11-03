#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int prime[15] = {2 ,3 ,5 ,7 ,11 ,13 ,17 ,19 ,23 ,29 ,31 ,37 ,41 ,43 ,47};
ll key = 1;
vector<int> a;
ll res = 1e18;
void dfs(int x) {
    if(x == 15) {
        bool ok = 1;
        for(ll i : a) {
            if(__gcd(i, key) == 1) {
                ok = 0;
            }
        }
        if(ok) {
            res = min(res, key);
        }
        return;
    }
    dfs(x + 1);
    key *= prime[x];
    dfs(x + 1);
    key /= prime[x];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    dfs(0);
    cout << res << '\n';
}