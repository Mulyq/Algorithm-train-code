#include<bits/stdc++.h>
using namespace std;
int a[51];
struct node
{
    int first;
    int last;
    int len;
}ti[51];

int main(){
    int q;cin>>q;
    while(q--){
        int n,ans=0;
        scanf("%d",&n);  
        for ( int i=0;i<n;i++)scanf("%d",&a[i]);
        int min_i = 0,k= 0;
        while( k != n-1 ){
            min_i=k;
            for(int i = k ;i<n ;i++)
            if(a[i]<a[min_i])min_i=i;
            if(k != min_i){
                ti[ans].first=k+1;
                ti[ans].last=min_i+1;
                ti[ans].len =min_i-k;
                ans++;
                
                int t =a[min_i];
                for(int j =min_i-1;j>=0;j--){
                    a[j+1]=a[j];
                }
                a[k]=t;
            }
            k++;
        }
        printf("%d\n",ans);
        for(int i=0 ;i< ans;i++)
        printf("%d %d %d\n",ti[i].first,ti[i].last,ti[i].len);
    }

    return 0;
}