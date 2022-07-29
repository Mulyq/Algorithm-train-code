#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
void solve() {
        map<int,int> mp;
        int n, res = 0;
        cin >> n;
        for(int i = 1; i <= sqrt(n); i ++){
            if(i <= 1000){
                if(i*i <= n && !mp[i*i]){
                    res ++;
                    mp[i*i] = 1;
                }
                if(i*i*i <= n && !mp[i*i*i]){
                    res ++;
                    mp[i*i*i] = 1;
                }
            }
            else{
                if(i*i <= n && !mp[i*i]){
                    res ++;
                    mp[i*i] = 1;
                }
            }
        }
        cout<<res<<endl;
        return;
}

int main(){
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}