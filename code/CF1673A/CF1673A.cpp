#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int a, b;
    a = b = 0;
    if(n % 2 == 0) {
        for(int i = 0; i < n; i ++) {
            a += s[i] - 'a' + 1;
        }
    } else {
        int t1 , t2;
        t1 = t2 = 0;
        for(int i = 1; i < n; i ++) {
            t1 += s[i] - 'a' + 1;
        }
        for(int i = 0; i < n - 1; i ++) {
            t2 += s[i] - 'a' + 1;
        }
        if(t1 >= t2) {
            a += t1;
            b += s[0] - 'a' + 1;
        } else {
            a += t2;
            b += s[n - 1] - 'a' + 1;
        }
    }
    if(a >= b) {
        cout << "Alice" << ' '  << a- b << '\n';;
    } else {
        cout << "Bob" << ' ' << b - a << '\n';
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