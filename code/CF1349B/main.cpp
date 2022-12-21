#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool ok = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] == k) ok = 1;
    }
    if(n == 1 && ok) {
        cout << "yes\n";
        return ;
    }
    for(int i = 0; i < n - 1; i ++) {
        if(a[i] >= k && a[i + 1] >= k && ok) {
            cout << "yes\n";
            return;
        }
    }
    for(int i = 0; i < n - 2; i ++) {
        int c = 0;
        for(int j = 0; j < 3; j ++) {
            if(a[i + j] >= k) c ++;
        }
        if(c >= 2 && ok) {
            cout << "yes\n";
            return ;
        } 
    }
    cout << "no\n";
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