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
    BIT(int n) : N(n){
        c.resize(N);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    BIT b(n + 1);
    while(m --) {
        int idx;
        cin >> idx;
        if(idx == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            b.add(x, k), b.add(y + 1, -k);
        }
        else {
            int x;
            cin >> x;
            cout << a[x] + b.ask(x) << '\n';
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