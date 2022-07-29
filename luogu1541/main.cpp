#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int dp[50][50][50][50];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), cnt(5);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    dp[0][0][0][0] = a[0];
    for(int i = 0; i <= cnt[1]; i ++) {
        for(int j = 0; j <= cnt[2]; j ++) {
            for(int k = 0; k <= cnt[3]; k ++) {
                for(int l = 0; l <= cnt[4]; l ++) {
                    int add = a[i + 2 * j + 3 * k + 4 * l];
                    int temp = 0;
                    if(i > 0) {
                        temp = max(temp, dp[i - 1][j][k][l]);
                    }
                    if(j > 0) {
                        temp = max(temp, dp[i][j - 1][k][l]);
                    }
                    if(k > 0) {
                        temp = max(temp, dp[i][j][k - 1][l]);
                    }
                    if(l > 0) {
                        temp = max(temp, dp[i][j][k][l - 1]);
                    }
                    dp[i][j][k][l] = add + temp;
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
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