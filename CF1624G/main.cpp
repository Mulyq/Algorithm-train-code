#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int p[N];
int find(int x) {
    if(p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}
void merge(int x, int y) {
    if(x != y);
    p[y] = x;
}
struct edge {
    int f, t, w;
    bool ban;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<edge> e(m);
    for(int i = 0;i < m;i ++) {
        cin >> e[i].f >> e[i].t >> e[i].w;
    }

    int res = 0;

    for(int i = 29;i >= 0;i --) {
        int cur = res + (1 << i);
        for(int i = 0;i <= n;i ++) p[i] = i;

        for(auto it : e) {
            if((it.w & cur) == 0) {
                merge(find(it.f), find(it.t));
            }
        }

        bool ok = 1;
        for(int i = 1;i <= n && ok;i ++) {
            if(find(i) != find(1)) ok = 0;
        }

        if(ok) {
            res = cur;
        }
    }
    cout << (1 << 30) - 1 - res  << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}