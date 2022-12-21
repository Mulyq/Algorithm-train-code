#include<bits/stdc++.h>
#define ll long long
const int N = 2e5 + 10;
using namespace std;
int a[N];
int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        int n,ans = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i ++) {
            scanf("%d",&a[i]);
        }
        int k = a[n - 1];
        for(int i = n - 1;i >= 0;i --) {
            if(a[i] > k) {
                ans ++;
                k = a[i];
            }
        }
        printf("%d\n",ans);
    }

}