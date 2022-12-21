#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;

int n, k, p[N], val[N], x, y, op, res;

void init() {
    for(int i = 1;i <= n;i ++) {
        p[i] = i;
        val[i] = 0;
    }
}
int find(int x) {
    if(p[x] != x) {
        int tmp = p[x];
        p[x] = find(p[x]);
        val[x] = (val[x] + val[tmp]) % 3;
    }
    return p[x];
}
void merge(int x, int y) {
    p[y] = x;
}
int main() {
    scanf("%d%d",&n, &k);
    init();
    while(k --) {
        scanf("%d%d%d",&op, &x ,&y);
        if(x > n || y > n) {
            res ++;
            continue;
        }
        int r1 = find(x), r2 = find(y);
        if(op == 1) {
            if(r1 != r2) {
                val[r2] = (val[x] - val[y] + 3 ) % 3;
                merge(r1, r2);
            }
            else {
                if(val[r2] != (val[x] - val[y] + 3 ) % 3)
                    res ++;
            }
        }
        else {
            if(r1 != r2) {
                val[r2] = (val[x] - val[y] + 4 ) % 3;
                merge(r1, r2);
            }
            else {
                if(val[r2] != (val[x] - val[y] + 4 ) % 3)
                    res ++;
            }
        }
    }
    printf("%d",res);
}