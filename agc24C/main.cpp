#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    if(a[0] != 0) {
        cout << "-1\n";
    } else {
        ll res = 0;
        for(int i = 1; i < n; i ++) {
            if(a[i] == a[i - 1] + 1) {
                res += 1;
            } else if(a[i] > a[i - 1] + 1) {
                cout << "-1\n";
                return 0;
            } else {
                res += a[i];
            }
        }
        cout << res << '\n';
    }
}