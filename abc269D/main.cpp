#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
map<PII, int> s;
const int dx[6] = {-1,-1,0,0,1, 1}, dy[6] = {-1,0,-1,1,0,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<PII> a(n);
    int xl = 0;
    for(auto &[x, y] : a) {
        cin >> x >> y;
        s[{x, y}] = xl ++;
    }
    int res = 0;
    vector<bool> vis(n);
    queue<PII> q;
    for(int i = 0; i < n; i ++) if(!vis[i]) {
        vis[i] = 1;
        q.push(a[i]);
        res ++;
        while(q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int j = 0; j < 6; j ++) if(s.find({x + dx[j], y + dy[j]}) != s.end() && !vis[s[{x + dx[j], y + dy[j]}]]) {
                q.push({x + dx[j], y + dy[j]});
                vis[s[{x + dx[j], y + dy[j]}]] = 1;
            }
        }
    }
    cout << res << '\n';
}