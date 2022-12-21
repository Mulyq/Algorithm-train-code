#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
// #include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int n, k;
vector<int> d(100010, -1);
int bfs() {
    queue<int> q;
    q.push(n);
    d[n] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(x == k) return d[x];
        if(x - 1 >= 0 && d[x - 1] == -1) q.push(x - 1), d[x - 1] = d[x] + 1;
        if(x + 1 <= 100000 && d[x + 1] == -1) q.push(x + 1), d[x + 1] = d[x] + 1;
        if(x * 2 <= 100000 && d[2 * x] == -1) q.push(2 * x), d[x * 2] = d[x] + 1;
    }
    return 0;
}
void solve() {
    cin >> n >> k;
    cout << bfs() << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}