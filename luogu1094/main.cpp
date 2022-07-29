#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int W, n;
    cin >> W >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i ++) {
        cin >> w[i];
    }
    int res = 0;
    sort(w.begin(), w.end());
    for(int i = 0, j = n - 1; i <= j;) {
        if(w[i] + w[j] <= W) {
            i ++, j --, res ++;
        } else {
            j --;
            res ++;
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