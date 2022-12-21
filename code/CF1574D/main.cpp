#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
struct build {
    int b[11];
    ll val;
    build() {
        memset(b, -1, sizeof b);
        val = 0;
    }
    bool operator< (const build &a) const {
        if(val != a.val) {
            return val < a.val;
        } else {
            for(int i = 0; i < 11; i ++) {
                if(b[i] != a.b[i]) {
                    return b[i] < a.b[i];
                }
            }
        }
        return 0;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i ++) {
        int m;
        cin >> m;
        a[i].resize(m);
        for(int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }
    set<build> S1, S2;
    int m;
    cin >> m;
    for(int i = 0; i < m; i ++) {
        build temp;
        for(int j = 0; j < n; j ++) {
            int x;
            cin >> x;
            x --;
            temp.b[j] = x;
            temp.val += a[j][x];
        }
        S1.insert(temp);
    }
    priority_queue<build> q;
    build fi;
    for(int i = 0; i < n; i ++) {
        fi.b[i] = a[i].size() - 1;
        fi.val += a[i][a[i].size() - 1];
    }
    q.push(fi);
    int c = 0;
    while(q.size()) {
        c ++;
        build x = q.top();
        q.pop();
        if(S1.find(x) == S1.end()) {
            for(int i = 0; i < n; i ++) {
                cout << x.b[i] + 1 << ' ';
            }
            return 0;
        }
        for(int i = 0; i < n; i ++) {
            build y = x;
            y.val -= a[i][y.b[i]];
            if(-- y.b[i] >= 0) {
                y.val += a[i][y.b[i]];
                if(S2.find(y) == S2.end()) {
                    q.push(y);
                    S2.insert(y);
                }
            }
        }
    }
    cout << c << '\n';
}