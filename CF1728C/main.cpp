#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int get(int x) {
    int res = 0;
    while(x) {
        res ++;
        x /= 10;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    priority_queue<int> a, b;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        b.push(x);
    }
    int res = 0;
    while(a.size()) {
        while(a.top() != b.top()) {
            int x = a.top(), y = b.top();
            a.pop(), b.pop();
            if(x > y) x = get(x);
            else y = get(y);
            a.push(x), b.push(y); 
            res ++;
        }
        a.pop(), b.pop();
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