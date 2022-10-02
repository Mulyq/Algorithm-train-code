#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<int> a, b;
int n, s;
int dp[110][10010][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    a.resize(n + 1), b.resize(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
    }
    dp[0][0][0] = dp[0][0][1] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int k = 0; k + a[i] <= s; k ++) {
            dp[i][k + a[i]][0] |= dp[i - 1][k][0];
            dp[i][k + a[i]][0] |= dp[i - 1][k][1];
        }
        for(int k = 0; k + b[i] <= s; k ++) {
            dp[i][k + b[i]][1] |= dp[i - 1][k][0];
            dp[i][k + b[i]][1] |= dp[i - 1][k][1];
        }
    }
    vector<char> res;
    if(dp[n][s][0] == 1) {
        cout << "Yes\n";
        int i = n - 1, t = s - a[n];
        res.push_back('H');
        while(i) {
            if(dp[i][t][0] == 1) res.push_back('H'), t -= a[i];
            else res.push_back('T'), t -= b[i];
            i --;
        }
    } else if(dp[n][s][1] == 1) {
        cout << "Yes\n";
        int i = n - 1, t = s - b[n];
        res.push_back('T');
        while(i) {
            if(dp[i][t][0] == 1) res.push_back('H'), t -= a[i];
            else res.push_back('T'), t -= b[i];
            i --;
        }
    } else {
        cout << "No\n";
    }
    if(res.size()) {
        reverse(res.begin(), res.end());
        for(char i : res) {
            cout << i;
        }
    }
}

