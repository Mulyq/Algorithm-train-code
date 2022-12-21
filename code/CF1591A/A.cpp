#include<bits/stdc++.h>
#define ll long long
const int N = 2e5 + 10;
using namespace std;
int a[N];
int main() {
    int T;
    scanf("%d",&T);
    while( T --) {
        int n;
        ll ans = 1;
        scanf("%d",&n);
        for(int i = 0;i < n;i ++ ) {
            scanf("%d",&a[i]);
        }
        ans += a[0];
        for(int i = 1; i < n;i ++) {
            if(a[i] == 1 && a[i - 1] == 1) {
                ans += 5; 
            }
            else if(a[i] == 0 && a[i - 1] == 0) {
                ans = - 1;
                break;
            }
            else if(a[i] != 0) {
                ans ++;
            }
        }
        printf("%d\n",ans);
    }
}