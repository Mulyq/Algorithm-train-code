#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] += i + 1;
    }
    stack<int> num;
    int idx = 0;
    vector<int> res;
    for(int i = 1;i <= 2 * n; i ++) {
        if(i != a[idx]) {
            num.push(i);
        }
        else {
            res.push_back( (i - num.top() + 1) / 2);
            num.pop(); 
            idx ++;
        }
    }
    for(int i = 0; i < res.size(); i ++) {
        cout << res[i];
        if(i != res.size() - 1) cout << ' ';
    }
    cout << '\n';
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