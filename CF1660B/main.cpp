#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    if(n == 1 && a[0] <= 1) {
        cout << "YES\n";
        return ;
    } else if (n == 1 && a[0] > 1){
        cout << "NO\n";
        return ;
    }
    sort(a.begin(), a.end());
    if(a[n - 1] - a[n - 2] > 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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