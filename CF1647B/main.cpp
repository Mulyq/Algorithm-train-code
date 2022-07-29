#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int> (m + 2));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            char temp;
            cin >> temp;
            a[i][j] = temp - '0';
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 3) {
                cout << "No\n";
                return ;
            }
        }
    }
    cout << "Yes\n";
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