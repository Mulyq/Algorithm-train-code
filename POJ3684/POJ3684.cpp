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
const double g = 10.0;
const int MAXN = 2e2 + 10;
using namespace std;
int n, h, r, t;
double y[MAXN];
double cal(int t) {
    if(t < 0) return h;
    double t0 = sqrt(2.0 * h / g);
    int tm = t / t0;
    if(tm % 2 == 0) {
        double tx = t - tm * t0;
        return h - 1.0 / 2.0 * g * tx * tx;
    } else {
        double tx = (tm + 1) * t0 - t;
        return h - 1.0 / 2.0 * g * tx * tx;
    }
    /*
        h = 1 / 2 g t^2
        t = √(2h / g)
    */
}
void solve() {
    scanf("%d %d %d %d", &n, &h, &r, &t);
    for(int i = 0; i < n; i ++) {
        y[i] = cal(t - i);
    }
    sort(y, y + n);
    for(int i = 0; i < n; i ++) {
        printf("%.2f%c", y[i] + 2 * r * i / 100.0, i == n - 1 ? '\n' : ' ');
    }
}
int main(){
    int _ = 1;
    scanf("%d", &_);
    while(_ --) {
        solve();
    }
    return 0;
}