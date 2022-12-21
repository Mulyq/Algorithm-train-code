#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    if(a[n - 1] < a[n - 2]) {
        cout << -1 << '\n';
        return ;
    } else {
        if(a[n - 1] < 0) {
            for(int i = 1; i < n; i ++) {
                if(a[i] < a[i - 1]) {
                    cout << -1 << '\n';
                    return;
                }
            }
            cout << 0 << '\n';
            return ;
        } else {
            vector<tuple<int, int, int>> rec;
            int res = 0;
            int i = n - 3;
            while(i >= 0) {
                if(a[i] > a[i + 1]) {
                    a[i] = a[i + 1] - a[n - 1];
                    rec.push_back({i + 1, i + 2, n});
                    res ++;
                }
                i --;
            }
            cout << res << '\n';
            for(auto x : rec) {
                cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << '\n';
            }
        }
    }
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