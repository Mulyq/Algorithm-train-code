#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
void solve() {
    int n, ans = 0;
    priority_queue<PII>q;
    vector<PII>res;
    cin >> n;
    for(int i = 0;i < n;i ++) {
        ll x;
        cin >> x;
        if(x)
            q.push({x, i + 1});
    }
    while(q.size() > 1) {
        PII a = q.top();
        q.pop();
        PII b = q.top();
        q.pop();
        if(--a.first)q.push(a);
        if(--b.first)q.push(b);
        res.push_back({a.second, b.second});
        ans ++;
    }
    cout << ans << '\n';
    for(auto it : res) {
        cout << it.first << ' ' << it.second << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}