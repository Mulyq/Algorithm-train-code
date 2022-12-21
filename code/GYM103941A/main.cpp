#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
string tab = "1023456789";
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n > tab.size()) {
        cout << "-1\n";
    } else {
        for(int i = 0; i < n; i ++) {
            cout << tab[i];
        }
        cout << '\n';
    }
}