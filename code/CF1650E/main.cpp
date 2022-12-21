#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;
int n, d;
int cal(vector<int> &b) {
    int mi = INF, mx = 0;
    for(int i = 1; i < b.size(); i ++) {
        mx = max(mx, b[i] - b[i - 1] - 1);
        mi = min(mi, b[i] - b[i - 1] - 1);
    }
    return min(mi, max(d - b[b.size() - 1] - 1, (mx - 1) >> 1));
}
void solve() {
    cin >> n >> d;
    vector<int> a(n + 1); 
    int min_idx, res = INF;
    for(int i = 1; i <= n;i ++) {
        cin >> a[i];
        if(a[i] - a[i - 1] - 1 < res)  {
            res = a[i] - a[i - 1] - 1;
            min_idx = i;
        }
    }
    vector<int> b;
    for(int i = 0; i <= n; i ++) {
        if(i != min_idx) {
            b.push_back(a[i]);
        }
    }
    res = max(res, cal(b));
    if(min_idx > 1) {
        min_idx --;
        b[min_idx] = a[min_idx + 1];
        res = max(res, cal(b));
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