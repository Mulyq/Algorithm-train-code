#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n), f(n);
    for (int &i : s) {
        cin >> i;
    }
    for (int &i : f) {
        cin >> i;
    }
    for(int i = 0; i < n; i ++) {
        if(i)
            cout << f[i] - max(f[ i - 1 ], s[i]) << ' ';
        else
            cout << f[i] - s[i] << ' ';
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
    return 0;
}