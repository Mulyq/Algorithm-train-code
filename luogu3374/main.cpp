#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
struct BIT {
    int N;
    vector<int> c;
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int d) {
        for(;x <= N; x += lowbit(x)) {
        	c[x] += d;
    	}
    }
    int ask(int x) {
       int res = 0;
        for(;x; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
    BIT(vector<int> a) : N(a.size()){
        c.resize(N);
        for(int i = 1;i < N;i ++) {
            add(i, a[i]);
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    BIT bit(a);
    while(m --) {
        int idx, x, y;
        cin >> idx >> x >> y;
        if(idx == 1) {
            bit.add(x, y);
        }
        else {
            cout << bit.ask(y) - bit.ask(x - 1) << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int _ = 1;
    // cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}