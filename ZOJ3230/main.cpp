#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int n, m, p;
void solve() {
    vector<PII> rec(n);
    for(int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >>b;
        rec[i] = {a, b};
    }
    sort(rec.begin(), rec.end()) ;
    priority_queue<int> q;
    int i = 0;
    while(rec[i].first <= p && i < n) {
        q.push(rec[i ++].second);
    }
    while(m --) {
        if(q.size()) {
            p += q.top();
            q.pop();
        } else {
            cout << p << '\n';
            return ;
        }
        while(rec[i].first <= p && i < n) {
            q.push(rec[i ++].second);
        }
    }
    cout << p << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    while(cin >> n >> m >> p) {
        solve();
    }
    return 0;
}