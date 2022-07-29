#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int all = 0;
    for(int i = 0; i < n; i ++)  {
        cin >> a[i];
        all += a[i];
    }
    int v = all / n;
    int res = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] == v) {
            continue;
        }
        if(a[i] < v) {
            res += 1;
            a[i + 1] -= (v - a[i]);
        } else {
            res += 1;
            a[i + 1] += (a[i] - v);
        }
    }
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}