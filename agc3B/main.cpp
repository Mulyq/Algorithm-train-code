#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll res = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) {
        cin >> i;
    }
    ll x = 0;
    for(int i = 0; i < n; i ++) {
        x += a[i];
        if(a[i] == 0 || i == n - 1) {
            res += x / 2;
            x = 0;
        }
    }
    cout << res << '\n';
}