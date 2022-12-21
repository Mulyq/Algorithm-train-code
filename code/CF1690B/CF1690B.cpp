#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    vector<int> c(n);
    int m = 0;
    for(int i = 0; i < n; i ++) {
        c[i] = a[i] - b[i];
        if(c[i] < 0) {
            cout << "NO\n";
            return ;
        }
        m = max(m, c[i]);
    }
    
    for(int i = 0; i < n; i ++) {
        if(c[i] != m) if(b[i] != 0) {cout << "NO\n";return ;}
    }
    cout << "YES\n";
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