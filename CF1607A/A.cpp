#include<bits/stdc++.h>

using namespace std;

int t,ans;
string str,s;
map<char,int>M;

int main(){
    for(scanf("%d",&t);t;--t){
        ans = 0;
        cin >> str >> s;
        for(int i = 0;i < str.size();i ++){
            M.insert(make_pair(str[i],i));
        }


        for(int i = 1;i < s.size();i ++){
            ans += abs(M[s[i]] - M[s[i - 1]]);
        }
        printf("%d\n",ans);
        M.clear();
    }
}
