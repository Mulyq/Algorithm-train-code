#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    ll res = 0;;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        q.push(t);
    }
    while(q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        res += a + b;
        q.push(a + b);
    }
    cout << res;
    return 0;
}