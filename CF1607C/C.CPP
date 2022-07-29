#include<bits/stdc++.h >

using namespace std;

const int N = 1e6 + 10;
int a[N];

int main(){
    int T;
    cin >> T;
    while(T --){
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n ;i ++)scanf("%d",&a[i]);
        sort(a,a + n);
        int ans = a[0];
        for(int i = 1;i < n;i ++)ans = max(ans,a[i] - a[i - 1]);
        printf("%d\n",ans);
    }
}