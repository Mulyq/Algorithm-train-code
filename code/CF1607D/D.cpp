#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int T,n,a[N];
string s;
int main(){
    scanf("%d",&T);
    while(T --){
        vector<int>b,r;
        scanf("%d",&n);
        for(int i = 0;i < n;i ++)scanf("%d",&a[i]);
        cin >> s;

        for(int i = 0;i < n;i ++)
            if(s[i] == 'B')b.push_back(a[i]);
            else r.push_back(a[i]);
        
        sort(b.begin(),b.end());
        
        sort(r.begin(),r.end());
        reverse(r.begin(),r.end());

        bool f  = 1;
        
        for(int i = 0;i < b.size();i ++){
            if(b[i] < i + 1)f = 0;
        }
        for(int i = 0;i < r.size();i ++){
            if(r[i] > n - i) f = 0;
        }

        printf(f?"YES":"NO");
        printf("\n");
    }
}