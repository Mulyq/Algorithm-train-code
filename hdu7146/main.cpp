#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
vector<PII> nd;
bool check(int x, int y) {
    for(int i = 0; i < nd.size(); i ++) {
        int X = nd[i].first, Y = nd[i].second;
        if(x != X && y != Y && Y - y != X - x && Y - y != x - X) {
            return 0;
        }
    }
    return 1;
}
void solve() {
    nd.clear();
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        nd.push_back({x, y});
    }
    queue<PII> q;
    int fx = nd[0].first, fy = nd[0].second;
    for(int i = 0; i < n; i ++) {
        int x1 = fx, y1 = fy;
        int x2 = nd[i].first, y2 = nd[i].second;
        if(x1 != x2 && y1 != y2 && y2 - y1 != x2 - x1 && y2 - y1 !=  x1 - x2) {
            q.push({x2, y1});
            q.push({x2, x2 - x1 + y1});
            q.push({x2, x1 + y1 - x2});
            q.push({x1, y2});
            q.push({y2 - y1 + x1, y2});
            q.push({y1 - y2 + x1, y2});
            q.push({x1, x1 - x2 + y2});
            q.push({y1 - y2 + x2, y1});
            q.push({(x1 - x2 + y1 + y2) / 2 - y2 + x2, (x1 - x2 + y1 + y2) / 2});
            q.push({x1, y2 - x1 + x2});
            q.push({y2 - y1 + x2, y1});
            q.push({ - (y2 + y1 + x2 - x1) / 2 + y2 + x2, (y2 + y1 + x2 - x1) / 2});
            break;
        }
    }
    if(!q.size()) {
        cout << "YES\n";
        return;
    }
    while(q.size()) {
        if(check(q.front().first, q.front().second)) {
            cout << "YES\n";
            return ;
        }
        q.pop();
    }
    cout << "NO\n";
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