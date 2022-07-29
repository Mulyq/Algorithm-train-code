#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int res = 0;
int n, k;
int node = 1;
int sum = 0;
void dfs(int x) {
    if(x  == k) {
        if(sum == n) {
            res ++;
        }
        return ;
    }
    for(int i = node; i < n; i ++) {
        sum += i;
        if(sum > n) {
            sum -= i;
            break;
        }
        int temp = node;
        node = i;
        dfs(x + 1);
        node = temp;
        sum -= i;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin >> n >> k;
    dfs(0);
    cout << res << '\n';
    return 0;
}