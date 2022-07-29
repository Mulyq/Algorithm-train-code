#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> even, odd;
    for(int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        if(t % 2 == 0) even.push_back(t);
        else odd.push_back(t);
    }
    bool f = 1;
    if(odd.size() > 1) {
        for(int i = 1; i < odd.size(); i ++) {
            if(odd[i] < odd[i - 1]) f = 0;
        }
    }
    if(even.size() > 1) {
        for(int i = 1; i < even.size(); i ++) {
            if(even[i] < even[i - 1]) f = 0;
        }
    }
    if(f)cout << "YES\n";
    else cout << "NO\n";
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