#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    if(n <= 2) {
        cout << n << '\n';
        return ;
    }
    else {
        if(n % 3 == 2) {
            while(n >= 3) {
                cout << 21;
                n -= 3;
            }
            cout << 2;
        } else if(n % 3 == 0){
            while(n >= 3) {
                cout << 21;
                n -= 3;
            }
        } else {
            cout << 1;
            n --;
            while(n >= 3) {
                cout << 21;
                n -= 3;
            }
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}