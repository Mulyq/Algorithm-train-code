#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
double cal(vector<int> &a, vector<int> &t, double x) {
    double res = -1e18;
    for(int i = 0; i < a.size(); i ++) {
        res = max(res, abs(a[i] - x) + t[i]);
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    double L = INF, R = - INF;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        L = min(L, 1.0 * a[i]), R = max(R, 1.0 * a[i]);
    }
    for(int i = 0; i < n; i ++) {
        cin >> t[i];
    }
    while(R - L >= 1e-6) {
        double ML = L + (R - L) / 3;
        double MR = R - (R - L) / 3;
        if(cal(a, t, ML) > cal(a, t, MR)) {
            L = ML;
        } else {
            R = MR;
        }
    }
    cout << fixed << setprecision(6) <<(L + R)  / 2 << '\n';
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