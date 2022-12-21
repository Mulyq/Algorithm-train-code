#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, mod = 998244353;
int n;
char s[(1 << 18) + 10];
ll dp[(1 << 18) + 10];
string dfs(int x) {
    dp[x] = 1;
    string sx = "";
    sx += s[x];
    if(2 * x  + 1 <= (1 << n) - 1) {
        string sl = dfs(2 * x), sr = dfs(2 * x + 1);
        if(sl < sr) {
            sx = sx + sl + sr;
        } else {
            sx = sx + sr + sl;
        }
        if(sl != sr) {
            dp[x] = (dp[2 * x] * dp[2 * x + 1] * 2) % mod;
        } else {
            dp[x] = (dp[2 * x] * dp[2 * x]) % mod;
        }
    }
    return sx;
}
void solve() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    dfs(1);
    printf("%lld", dp[1]);
}
int main() {
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}