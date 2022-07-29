#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
vector<int> p, val;
int find(int x) {
    if(p[x] != x) {
		int tmp = p[x];
        p[x] = find(p[x]);
        val[x] = (val[x] + val[tmp] ) % 3;
    }
    return p[x];
}
bool merge(int op, int x, int y) {
	int r1 = find(x), r2 = find(y);
    if(r1 != r2) {
		p[r2] = r1;
        val[r2] = (2 + op + val[x] - val[y]) % 3;
    }
    else {
		if(val[r2] != (2 + op + val[x] - val[y]) % 3) {
            return 1;
        }
    }
    return 0;
}
void solve() {
    int n, k, res = 0;
    cin >> n >> k;
    p.resize(n + 1);
    val.resize(n + 1);
    for(int i = 1; i <= n;i ++) {
		p[i] = i;
        val[i] = 0;
    }
    while(k --) {
        int op, x, y;
        cin >> op >> x >> y;
        if(x > n || y > n) {
			res ++;
            continue;
        }
        if(merge(op, x, y)) res ++;
    }
    cout << res;
}
int main() {
    solve();
}