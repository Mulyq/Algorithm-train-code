#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    struct bb {
        int cnt;
        vector<int> pos;
        bool operator< (const bb & a) const {
            return cnt < a.cnt;
        }
    };
    vector<bb> pos(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        pos[a[i]].pos.push_back(i);
        pos[a[i]].cnt ++;
    }
    priority_queue<bb> q;
    for(int i = 1; i <= n; i ++) {
        if(pos[i].cnt) {
            q.push(pos[i]);
        }
    }
    while(q.size() > 1) {
        bb x = q.top();
        q.pop();
        bb y = q.top();
        q.pop();
        if(q.size() == 1) {
            bb z = q.top();
            q.pop();
            if(x.cnt == 1) {
                swap(a[y.pos.back()], a[x.pos.back()]);
                swap(a[y.pos.back()], a[z.pos.back()]);
                x.pos.pop_back();
                y.pos.pop_back();
                z.pos.pop_back();
                x.cnt --;
                y.cnt --;
                z.cnt --;
            } else {
                q.push(z);
            }
        }
        while(y.pos.size()) {
            swap(a[y.pos.back()], a[x.pos.back()]);
            x.pos.pop_back();
            y.pos.pop_back();
            x.cnt --;
            y.cnt --;
        }
        if(x.cnt) {
            q.push(x);
        }
    }
    for(int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
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