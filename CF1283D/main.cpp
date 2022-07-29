#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<int> pos;
    priority_queue<PII, vector<PII> ,greater<PII>> q;
    ll res = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        pos.insert(x);
        q.push({0, x});
    }
    vector<int> pla;
    set<int> vis;
    while(q.size()) {
        int x = q.top().second, w = q.top().first;
        q.pop();
        if(pos.find(x) == pos.end()) {
            pos.insert(x);
            res += w;
            pla.push_back(x);
        }
        if(vis.find(x + 1) == vis.end()) {
            q.push({w + 1, x + 1});
            vis.insert(x + 1);
        }
        if(vis.find(x - 1) == vis.end()) {
            q.push({w + 1, x - 1});
            vis.insert(x - 1);
        }
        if(pla.size() == m) break;
    }
    cout << res << '\n';
    for(auto x : pla) {
        cout << x << ' ';
    }
}