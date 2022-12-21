#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n, maxa = - 1, res = 0;
    cin >> n;
    vector<int> a(N);
    for(int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        a[t] = 1;
        maxa = max(maxa, t);
    }
    for(int i = 1; i < maxa; i ++) {
        if(!a[i]) {
            int m = 1;
            vector<int> tmp;
            while(i * m <= maxa) {
                if(a[i * m]) {
                    tmp.push_back(i * m);
                }
                m ++;
            }
            if(tmp.size() >= 2) {
                int g = tmp[0];
                for(int i = 1; i < tmp.size(); i ++) {
                    g = __gcd(g, tmp[i]);
                }
                if(g == i) res ++;
            }
        }
    }
    cout << res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}