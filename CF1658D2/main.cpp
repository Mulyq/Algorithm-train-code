#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int son[10000000][2];
int idx;
void insert(int x) {
    int p = 0;
    for(int i = 17; i >= 0; i --) {
        int u = x >> i & 1;
        if(!son[p][u]) {
            son[p][u] = ++ idx;
        }
        p = son[p][u];
    }
}
//询问字典树中xor x意义下的最大值
int query_mx(int x) {
    int p = 0, res = 0;
    for(int i = 17; i >= 0; i --) {
        int s = x >> i & 1;
        if(son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        } else {
            p = son[p][s];
        }
    }
    return res ;
}
//询问字典树中xor x意义下的最小值
int query_mn(int x) {
    int p = 0, res = 0;
    for(int i = 17; i >= 0; i --) {
        int s = x >> i & 1;
        if(son[p][s]) {
            p = son[p][s];
        } else {
            res += (1 << i);
            p = son[p][!s];
        }
    }
    return res;
}
void solve() {
    int l, r;
    cin >> l >> r;
    for(int i = 0; i <= idx; i ++) {
        son[i][0] = son[i][1] = 0;
    }
    idx = 0;
    vector<int> a;
    for(int i = l; i <= r; i ++) {
        int x;
        cin >> x;
        a.push_back(x);
        insert(x);
    }
    int res = 0;
    for(int i = l; i <= r; i ++) {
        int x = a[i - l] ^ l;
        // cout << x << ' ';
        // cout << query_mn(x) << ' ' << query_mx(x) << '\n';
        if(query_mn(x) == l && query_mx(x) == r) {
            res = x;
            break;
        }
    }
    cout << res << '\n';
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