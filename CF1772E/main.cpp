#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), f(n), s(n);
    vector<int> c(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        f[i] = i + 1;
        s[i] = n - i;
    }
    int fl = 0, sl = 0;
    int fr = 0, sr = 0;
    int gg = 0;
    for(int i = 0; i < n; i ++) {
        if(f[i] != a[i]) fr ++;
        if(s[i] != a[i]) sr ++;
        if(f[i] != a[i] && s[i] != a[i]) {
            gg ++;
        }
    }
    // cout << fr << ' ' << sr << ' ' << gg << '\n';
    int x = fr - gg , y = sr - gg;
    while(1) {
        if(x) fr --, x --;
        else fr --, sr --, gg --;
        if(fr == 1 && sr == 1 && gg == 1) {
            cout << "Tie\n";
            return ;
        }
        if(y) sr --, y --;
        else fr --, sr --, gg --;
        if(fr == 1 && sr == 1 && gg == 1) {
            cout << "Tie\n";
            return ;
        }
        if(!fr) {
            cout << "First\n";
            return;
        }
        if(!sr) {
            cout << "Second\n";
            return;
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
}