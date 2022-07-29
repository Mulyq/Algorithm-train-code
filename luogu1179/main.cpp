#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l , r, res = 0;
    cin >> l >> r;
    for(int i = l; i <= r; i ++) {
        int temp = i;
        while(temp) {
            if(temp % 10 == 2) res ++;
            temp /= 10;
        }
    }
    cout << res;
    return 0;
}