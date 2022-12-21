#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int res = n - 2;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    if(n <= 2) {
        cout << 0 << '\n';
        return ;
    }
    for(int i = 0; i < n; i ++) {
        map<double, int> cnt;
        for(int j = 0; j < i; j ++) {
            double d = (double)(a[i] - a[j]) / (double)(i - j);
            cnt[d] ++;
        }
        for(int j = i + 1; j < n; j ++) {
            double d = (double)(a[j] - a[i]) / (double)(j - i);
            cnt[d] ++;
        }
        for(auto x : cnt) {
            res = min(res, n - x.second - 1);
        }
    }
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}