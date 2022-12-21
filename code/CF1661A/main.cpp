#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i ++)
        if(a[i] < b[i]) {
            swap(a[i], b[i]);
        }
    ll res = 0;
    for(int i = 1; i < n; i ++) {
        res += abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
    }
    cout << res <<'\n';
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