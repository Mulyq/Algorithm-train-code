#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
bool cmp(PII a, PII b) {
    return a.second < b.second;
}
int T_T;
void solve() {
    int n, k, res = 0;
    cin >> n >> k;
    vector<PII> a(n);
    vector<int> b(n);
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first >> a[i].second;
        b[i] = a[i].second;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0, j = 0; i < n; i ++) {
        while(j < n && a[j].first <= b[i]) {
            q.push(a[j].second);
            j ++;
        }
        int c = 0;
        while(q.size() && q.top() == b[i]) {
            q.pop();
            c ++;
        }
        res += (c + k - 1) / k;
        int ex = (k - c % k) % k;
        for(int w = 0; w < ex && q.size(); w ++) {
            q.pop();
        }
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    for(T_T = 1; T_T <= _; T_T ++) {
        solve();
    }
    return 0;
}