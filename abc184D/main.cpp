#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
double dp[101][101][101];
double f(int a, int b, int c) {
    if(dp[a][b][c]) return dp[a][b][c];
    if(a == 100 || b == 100 || c == 100) {
        return dp[a][b][c];
    }
    double res = 0;
    res += (f(a + 1, b, c) + 1) * a / (a + b + c);
    res += (f(a, b + 1, c) + 1) * b / (a + b + c);
    res += (f(a, b, c + 1) + 1) * c / (a + b + c);
    return dp[a][b][c] = res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double res = 0;
    int x, y, z;
    cin >> x >> y >> z;
    cout << fixed << setprecision(6) << f(x, y, z) << '\n';
}