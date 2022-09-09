#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    priority_queue<PII> q;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        q.push({x, i + 1});
    }
    while(q.size() > 1) {
        PII x = q.top();
        q.pop();
        PII y = q.top();
        q.pop();
        x.first -= y.first;
        q.push(x);
    }
    cout << q.top().second << '\n';
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