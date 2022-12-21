#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll s,n,f,ans;
int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        cin >> s >> n;

        if(s % 2 == 0)f = - 1;
        else f = 1;

        if(n % 4 == 1) ans = s + f + f*4*(n/4);
        else if(n % 4 == 2)ans = s - f;
        else if(n % 4 == 3)ans = s - f*4*(n/ 4 + 1);
        else ans = s;
        printf("%lld\n",ans);
    }
}