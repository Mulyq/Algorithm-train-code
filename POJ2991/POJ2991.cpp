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
#define pi 3.1415926535
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e4 + 10;
int L[N], A[N], S[N];
int n, c;
double vx[N << 2], vy[N << 2], ang[N << 2];
//区间[l, r]保存这个区间的向量。
void build(int k, int l, int r) {
    ang[k] = vx[k] = 0;
    if(l == r) {
        vy[k] = L[l];
        return ;
    }
    int m = l + r >> 1;
    build(k << 1, l, m), build(k << 1 | 1, m + 1, r);
    vy[k] = vy[k << 1] + vy[k << 1 | 1];
}
void updata(int k, int l, int r, int x, double d) {
    if(l == r && l >= x) {
        ang[k] = ang[k] + d;
        vx[k] = L[l] * sin(ang[k]);
        vy[k] = L[l] * cos(ang[k]);
        return ;
    }
    int m = l + r >> 1;
    if(x <= m) updata(k << 1, l, m, x, d), updata(k << 1 | 1, m + 1, r, x, d);
    else updata(k << 1 | 1, m + 1, r, x, d);
    vy[k] = vy[k << 1] + vy[k << 1 | 1];
    vx[k] = vx[k << 1] + vx[k << 1 | 1];
}
void solve() {
    
    for(int i = 1;i <= n; i ++) {
        scanf("%d", &L[i]);
    }
    build(1, 1, n);
    for(int i = 1; i <= c; i ++) {
        int s, temp;
        scanf("%d %d", &s, &temp);
        double a = 2 * pi * temp / 360;
        updata(1, 1, n, s + 1, a);
        printf("%.2f %.2f\n", vx[1], vy[1]);
    }
}
int main(){
    while(scanf("%d %d", &n, &c) != EOF) {
        // scanf("%d %d", &n, &c);
        solve();
        printf("\n");
    }
    return 0;
}