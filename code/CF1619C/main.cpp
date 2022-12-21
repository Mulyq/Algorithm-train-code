#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
bool cmp(ll a, ll b) {
    return a > b;
}
void solve() {
    ll a, c;
    cin >> a >> c;
    if(cmp(a,c)) {
        cout << -1 << '\n';
        return ;
    }
    vector<int>b;
    while(c){
        int x = a % 10;
        int y = c % 10;
        if(x <= y) b.push_back(y - x);
        else{
            c /= 10;
            y += 10 * (c % 10);
            if(x < y && y >= 10 && y <= 19) b.push_back(y - x);
            else{
                cout << -1 << '\n';
                return ;
            }
        }
        a /= 10;
        c /= 10;
    }
    if(a) cout << -1 << '\n';
    else{
        while (b.back() == 0) b.pop_back();
        for(int i = b.size() - 1; i >= 0; i--) cout << b[i];
        cout << '\n';
    }
}
int main(){
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}