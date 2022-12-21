#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
    }
    int res = 0;
    for(int i = a.size() - 2; i >= 0; i --) {
        while(a[i] >= a[i + 1] && a[i]) a[i] >>= 1, res ++;
    }
    for(int i = 0; i < n - 1; i ++) {
        if(a[i] == a[i + 1]) {
            cout << "-1\n";
            return ;
        }
    }
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