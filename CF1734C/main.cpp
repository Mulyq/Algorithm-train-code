#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<bool> T(n + 1), S(n + 1);
    for(int i = 0; i < n; i ++) {
        T[i + 1] = t[i] - '0';
        S[i + 1] = T[i + 1];
    }
    ll res = 0;
    for(int i = 1; i <= n; i ++) {
        for(int k = 1; i * k <= n; k ++) {
            if(S[i * k] == 0) {
                S[i * k] = 1;
                res += i;
            } else if(T[i * k] == 1) {
                break;
            }
        }
    }
    cout << res << '\n';
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