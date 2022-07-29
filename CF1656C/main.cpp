#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) ok = 0;
    }
    if(ok) {
        cout << "Yes\n";
    } else {
        sort(a.begin(), a.end());
        for(int i = 0; i < n - 1; i ++) {
            if(a[i] + 1 == a[i + 1]) {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    }
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