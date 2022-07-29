#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    int a = 2, b = 3, c = 1;
    for(int i = 0; i < n - 6; i ++) {
        if(i % 3 == 0) b ++;
        else if (i % 3 == 1)a ++;
        else c ++;
    }
    printf("%d %d %d\n", a, b, c);
}
int main() {
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}