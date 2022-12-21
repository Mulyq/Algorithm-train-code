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
    vector<int> s(n), a(n + 2);
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    a[2] = s[0], a[3] = s[1] - s[0];
    for(int i = 4; i < n + 2; i ++) {
        a[i] = s[i - 2] - a[i - 1] - a[i - 2];
    }
    int x = 0, y = 0;
    for(int i = 0; i < n + 2; i += 3) {
        x = min(x, a[i]);
        if(i + 1 < n + 2) {
            y = min(y, a[i + 1]);
        }
    }
    a[0] = -x, a[1] = -y;
    for(int i = 2; i < n + 2; i ++) {
        if(i % 3 == 0) a[i] += a[0];
        else if(i % 3 == 1) a[i] += a[1];
        else a[i] -= a[0] + a[1];
        if(a[i] < 0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for(int i : a) {
        cout << i << ' ';
    }
}