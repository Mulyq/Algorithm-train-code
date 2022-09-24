#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define int ll
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
int n, k;
struct block {
    int sub, add;
    block(int a, int b) {
        sub = a, add = b;
    }
};
bool check(vector<int> &a, int x) {
    vector<block> v;
    for(int i = x + 1, j = x + 1; i < n; i = j) {
        block temp(0, 0);
        int pre = 0;
        do {
            pre += a[j];
            temp.sub = min(temp.sub, pre);
            j ++;
        } while(j < n && pre <= 0);
        temp.add = pre;
        if(pre > 0) {
            v.push_back(temp);
        }
    }
    int now = a[x];
    for(int i = x - 1, j = 0; i >= 0; i --) {
        while(j < v.size() && now + v[j].sub >= 0) {
            now += v[j].add;
            j ++;
        }
        if(now + a[i] < 0) return 0;
        else now += a[i];
    }
    return 1;
}
void solve() {
    cin >> n >> k; k --;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    bool res = 0;
    res |= check(a, k);
    reverse(a.begin(), a.end());
    k = n - k - 1;
    res |= check(a, k);
    cout << (res ? "Yes" : "No") << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}