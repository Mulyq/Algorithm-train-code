#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
int T;
void solve() {
    int r = 0, l = 1 << 30;
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i ++) {
        cin >> a[i];
        r = max(r , a[i]);
        l = min(l, a[i]);
    }
    cout << r - l << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}