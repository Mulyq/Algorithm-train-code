#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    for(int i = 0; i < n; i ++) {
        if(a[i] != i + 1) {
            reverse(a.begin() + i, a.begin() + b[i + 1] + 1);
            break;
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return ;
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