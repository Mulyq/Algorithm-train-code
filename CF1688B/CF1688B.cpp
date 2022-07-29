#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int res = 0;
    int mi = INF;
    int oo = 0;
    for(int i = 0; i < n; i ++) {
        int k = a[i];
        int c = 0;
        if(k % 2 == 0) {
            oo ++;
        }
        while(k % 2 == 0) {
            k /= 2;
            c ++;
        }
        mi = min(mi, c);
    }
    res = mi;
    if(oo < n)
        res += oo;
    else 
        res += oo - 1;
    cout << res << '\n';
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