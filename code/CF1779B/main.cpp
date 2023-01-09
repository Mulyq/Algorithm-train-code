#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    if(n == 3) {
        cout << "No\n";
        return;
    } else {
        cout << "YES\n";
    }
    vector<int> a(n);
    if(n & 1) {
        int x = -(n / 2 - 1);
        int y = n / 2;
        for(int i = 0; i < n; i ++) {
            if(i & 1) {
                a[i] = y;
            } else {
                a[i] = x;
            }
        }
    } else {
        for(int i = 0; i < n; i += 2) {
            a[i] = 1;
            a[i + 1] = -1;
        }
    }
    for(int i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}