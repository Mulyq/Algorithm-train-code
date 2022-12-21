#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
vector<int> mp(N);
void solve() {
    int n, k;
    cin >> n >> k;
    int w = 0;
    vector<int> b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++) {
        int tmp; cin >> tmp;
        b[i] = mp[tmp];
        w += b[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    k = min(k, w);
    vector<ll> dp(k + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = k; j >= b[i]; j --) {
            if (dp[j - b[i]] + c[i] > dp[j]) {
                dp[j] = dp[j - b[i]] + c[i];
            }
        }
    }
    cout << dp[k] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    mp[1] = 0;
    for(int i = 1; i < 1e3 + 1;i ++) {
        for(int j = 1; j <= i; j ++) {
            int x = i + i / j;
            if(x <= 1e3 + 10) {
                if(!mp[x]) {
                    mp[x] = mp[i] + 1;
                }
                else {
                    mp[x] = min(mp[x], mp[i] + 1);
                }
            }
        }
    }
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}