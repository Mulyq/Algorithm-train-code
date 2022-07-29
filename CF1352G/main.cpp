#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    if(n <= 3) {
        cout << -1 << '\n';
        return ;
    }
    vector<int> res;
    if(n % 2 == 1) {
        for(int i = 0; i <= n / 2; i ++) {
            res.push_back(2 * i + 1);
        }
        res.push_back(n - 3);
        res.push_back(n - 1);
        for(int i = n - 5; i > 1; i -= 2) {
            res.push_back(i);
        }
    } else {
        for(int i = 2; i <= n; i += 2) {
            res.push_back(i);
        }
        res.push_back(n - 3);
        res.push_back(n - 1);
        for(int i = n - 5; i >= 1; i -= 2) {
            res.push_back(i);
        }
    }
    for(auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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