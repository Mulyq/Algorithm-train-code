#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
ll x;
ll a[14] = {1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200};
int res = INF, k = 0;
void dfs(int s) {
    if(s == 14) {
        ll temp = x;
        int w = k;
        while (temp) {
            temp -= temp & (- temp);
            k ++;
        }
        res = min(res, k);
        k = w;
        return;
    }
    dfs(s + 1);
    if(x - a[s] >= 0) {
        x -= a[s];
        k ++;
        dfs(s + 1);
        k --;
        x += a[s];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        cin >> x;
        k = 0;
        res = INF;
        dfs(0);
        cout << res << '\n';
    }
    return 0;
}