#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<PII, vector<PII>, greater<PII>> p;
    vector<PII> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].second;
    }
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i ++) {
        p.push(a[i]);
    }
    ll sum = k;
    while(1) {
        while(p.size()) {
            if(p.top().second <= sum) {
                p.pop();
            } else {
                break;
            }
        }
        if(p.empty()) {
            cout << "YES\n";
            break;
        } else {
            k -= p.top().first;
        }
        if(k <= 0) {
            cout << "NO\n";
            break;
        }
        sum += k;
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
}