#include<bits/stdc++.h>
using namespace std;
void solve() {
    int s;
    long long x, y, cnt;  
    int a1, a2, a3, a4, a5, a6; 
    int c[4]={0,5,3,1};  
    cnt = 0;
    scanf("%d%d%d%d%d%d%d",&s, &a1, &a2, &a3, &a4, &a5, &a6);
    cnt += a6 + a5 + a4 + (a3 + 3) / 4; 
    x = 5 * a4 + c[a3 % 4];
    if(a2 > x) 
        cnt += (a2 - x + 8) / 9; 
        y = 36 * cnt - 36 * a6 - 25 * a5 - 16 * a4 - 9 * a3 - 4 * a2; 
    if(a1 > y)
        cnt += (a1 - y + 35) / 36;
    if(cnt > s) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}
int main () {
    int t;
    scanf("%d", &t);
    while(t --) {
        solve();
    }
}