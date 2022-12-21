#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    if(n < 4 || n == 6) {cout << -1 << '\n';}
    else {
        if(n == 4) cout << "2 0 2 0 \n";
        else if(n == 5) cout << "2 1 2 0 0 \n";
        else {
            vector<int> a(n);
            a[0] = n - 4, a[1] = 2, a[2] = 1, a[n - 4] = 1;
            for(int i : a) {
                cout << i << ' ';
            }
            cout << '\n';
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
    return 0;
}

/*
1 2 1 0 
2 0 2 0 
2 1 2 0 0 
3 2 1 1 0 0 0 
4 2 1 0 1 0 0 0 
5 2 1 0 0 1 0 0 0 
*/