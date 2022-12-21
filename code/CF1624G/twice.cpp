#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
vector<int>p;
struct edge {
    int f, t, w;
    bool ban;
};
int find(int x) {
    if(p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}
void solve () {
    int n, m;
    cin >> n >> m;
    vector<edge>e(m);
    p.resize(n + 1);
    for(auto & i : e) {
        cin >> i.f >> i.t >> i.w;
        i.ban = 0;
    }
    int res = 0;
    for(int i = 30;i >= 0;i --) {
        int cnt = 0;
        for(int j = 1;j <= n;j ++) {
            p[j] = j;
        }

        for(auto &it : e) {
            int r1 = find(it.f), r2 = find(it.t);
            if(r1 != r2 && (it.w & (1 << i)) == 0 && !it.ban) {
                p[r2] = r1;
                cnt ++;
            }
        }

        bool ok = (cnt >= n - 1);

        if(ok) {
            for(auto &it : e) {
                if((it.w & (1 << i))) it.ban = 1;
            }
        }
        else {
            res += (1 << i);
        }
    }
    cout << res << '\n';
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