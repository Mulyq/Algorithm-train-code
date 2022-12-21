#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] *= 3;
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i ++) {
        if(b[i] > a[i]) {
            cout << i + 1 << '\n';
            return ;
        }
    }
    cout << - 1 << '\n';
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