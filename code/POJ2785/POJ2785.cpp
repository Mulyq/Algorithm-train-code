#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 4e3 + 10;
int a[N], b[N], c[N], d[N], ab[N * N], cd[N * N];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d %d %d %d", &a[i], &b[i], &c[i], & d[i]);
    int k = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            ab[k ++] = a[i] + b[j];
        }
    }
    k = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cd[k ++] = c[i] + d[j];
        }
    }
    sort(cd, cd + n * n);
    int res = 0;
    for(int i = 0; i < n * n; i ++) {
        int x = ab[i];
        int y = -ab[i];
        res += upper_bound(cd, cd + n * n, y) - lower_bound(cd, cd + n * n, y);
    }
    printf("%d", res);
}
int main(){
    int _ = 1;
    //scanf("%d", &_);
    while(_ --) {
        solve();
    }
    return 0;
}