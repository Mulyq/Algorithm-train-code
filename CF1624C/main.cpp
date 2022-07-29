#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
int n;
void solve() {
    cin >> n;
    vector<bool> f(n + 1, 0);
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    for(auto i : a) {
        while(i > n || f[i] == 1) {
            i >>= 1;
        }
        if(i != 0) {
            f[i] = 1;
        }
        else {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}