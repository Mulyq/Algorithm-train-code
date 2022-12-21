#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e4 + 10;

int dp[N][N];
int n, s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin >> n >> s;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        for(int j = a; j < N; j ++) {
            dp[i][j] = max(dp[i - 1][j - a],dp[i][j]);
        }
        for(int j = b; j < N; j ++) {
            dp[i][j] = max(dp[i - 1][j - b], dp[i][j]);
        }
    }
    if(dp[n][s]) cout << "Yes";
    else cout << "No";
    return 0;
}