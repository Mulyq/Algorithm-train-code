#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll x ;
    cin >> x;
    if(x > 0) {
        cout << x / 10;
    }
    else cout << (x - 9) / 10;
    return 0;
}