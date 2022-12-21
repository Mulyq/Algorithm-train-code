#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    deque<int> o, z;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(x) o.push_back(i);
        else z.push_back(i);
    }
    int res = 0;
    while(z.size()) {
        if(o.front() < z.front()) {
            o.pop_front();
            z.pop_back();
            res ++;
        } else {
            z.pop_front();
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