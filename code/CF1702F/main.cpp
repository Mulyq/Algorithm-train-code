#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    multiset<int> a;
    priority_queue<int> b;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        while(!(x & 1)) {
            x >>= 1;
        }
        a.insert(x);
    }
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        while(!(x & 1)) {
            x >>= 1;
        }
        b.push(x);
    }
    while(a.size()) {
        int x = b.top();
        b.pop();
        auto it = a.find(x);
        if(it != a.end()) {
            a.erase(it);
        } else {
            x >>= 1;
            b.push(x);
        }
        if(!x) {
            cout << "NO\n";
            return ;
        }
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