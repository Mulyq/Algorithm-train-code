#include<bits/stdc++.h>
#define ll long long
const int N = 2e5 + 10;
using namespace std;
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        int n,k,maxx = - 1;
        ll ans = 0;
        vector<int>v1,v2;
        scanf("%d%d",&n,&k);
        for(int i = 0;i < n;i ++) {
            int t;
            scanf("%d",&t);
            if(t > 0) {
                v1.push_back(t);
            }
            else {
                v2.push_back(-t);
            }
            maxx = max(maxx,abs(t));
        }
        sort(v1.begin(),v1.end(),cmp);
        sort(v2.begin(),v2.end(),cmp);
        for(int i = 0;i < v1.size();i += k) {
            ans += v1[i] * 2;
        }
        for(int i = 0;i < v2.size();i += k) {
            ans += v2[i] * 2;
        }
        ans -= maxx;
        printf("%lld\n",ans);
    }
}