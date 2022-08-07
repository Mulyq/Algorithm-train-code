#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    deque<int> v;
    for(int i = 1; i <= (1 << n); i ++) {
        v.push_back(i);
    }
    while(v.size() >= 4) {
        int a = v.front();
        v.pop_front();
        int b = v.front();
        v.pop_front();
        int c = v.front();
        v.pop_front();
        int d = v.front();
        v.pop_front();
        cout << "? " << a << ' ' << c << '\n';
        int x;
        cin >> x;
        if(x == 0) {
            cout << "? " << b << ' ' << d << '\n';
            cin >> x;
            if(x == 1) v.push_back(b);
            else v.push_back(d);
        } else if(x == 1) {
            cout << "? " << a << ' ' << d << '\n';
            cin >> x;
            if(x == 1) v.push_back(a);
            else v.push_back(d);
        } else {
            cout << "? " << b << ' ' << c << '\n';
            cin >> x;
            if(x == 1) v.push_back(b);
            else v.push_back(c);
        }
    }
    if(v.size() == 2) {
        int a = v[0], b = v[1];
        v.pop_front();
        v.pop_front();
        cout << "? " << a << ' ' << b << '\n';
        int x;
        cin >> x;
        if(x == 1) {
            v.push_back(a);
        } else {
            v.push_back(b);
        }
    }
    cout << "! " << v[0] << '\n';
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}