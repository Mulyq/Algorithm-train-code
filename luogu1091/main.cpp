#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
/*
枚举每一个人作为最高位
vl是左端的最长上升子序列
vr是右端的最长下降子序列
*/
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> vl(n), vr(n);
    for(int i = 0; i < n; i ++) {
        vl[i] = 1;
        for(int j = 0; j < i; j ++) {
            if(a[j] < a[i]) {
                vl[i] = max(vl[i], vl[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = n - 1; i >= 0; i --) {
        vr[i] = 1;
        for(int j = n - 1; j >= i; j --) {
            if(a[j] < a[i]) {
                vr[i] = max(vr[i], vr[j] + 1);
            }
        }
    }
    for(int i = 0 ; i < n; i ++) {
        res = max(res, vl[i] + vr[i] - 1);
    }
    cout << n - res << '\n';
    // for(int i = 0; i < n; i ++) {
    //     cout << vl[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < n; i ++) {
    //     cout << vr[i] << ' ';
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}