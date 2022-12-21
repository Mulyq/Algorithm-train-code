#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> h(n);
    for(int i = 0, j = n - 1, k = 0; i <= j; i ++, j --, k ++) {
        h[k] = a[j];
        if(i != j)
            h[++ k] = a[i];
    }
    ll res = 0;
    for(int i = 0; i < n ;i ++) {
        if(!i) {
            res += h[i] * h[i];
        } else {
            res += (h[i] - h[i - 1]) * (h[i] - h[i - 1]);
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