#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a -- , b --;
    vector<int> w(n);
    for(int i = 0; i < n; i ++) {
        cin >> w[i];
    }
    vector<bool> vis(n);
    queue<PII> q;
    q.push({a, 0});
    while(q.size()) {
        auto x = q.front();
        int fl = x.first;
        if(x.first == b) {
            cout << x.second;
            return;  
        }
        q.pop();
        if(vis[fl]) continue;
        vis[fl] = 1;
        if(fl + w[fl] < n) {
            q.push({fl + w[fl], x.second + 1});
        }
        if(fl - w[fl] >= 0) {
            q.push({fl - w[fl], x.second + 1});
        }
    }   
    cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}