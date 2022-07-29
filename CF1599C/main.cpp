#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double p;
    cin >> n >> p;
    for(int i = 0; i < 3; i ++) {
        p *= (n - i);
    }
    p /= 6;
    for(int res = 0; res <= n - 1; res ++) {
        double t = 1.0 * res * (n - res) * (n - res - 1) / 4 + 1.0 * res * (res - 1) * (n - res) / 2 + 1.0 * res * (res - 1) * (res - 2) / 6;
        if(t >= p) {
            cout << res << '\n';
            return 0;
        }
    }
}