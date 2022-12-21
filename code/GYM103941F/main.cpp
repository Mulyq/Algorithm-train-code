#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n % 2 == 1) {
        int x = (n + 1) / 2;
        cout << x << '\n';
        for(int i = 1; i <= x; i ++) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        if(n >= 6) {
            int x = n / 2;
            cout << x << '\n';
            for(int i = 1, j = 1; j <= x; i ++, j ++) {
                if(i == 2) {
                    i ++;
                }
                cout << i << ' ';
            }
        } else {
            cout << "-1\n";
        }
    }
}