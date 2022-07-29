#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 30;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > a(n,vector<int> (m, 0));
    for(int i = 0;i < n;i ++) {
        for(int j = 0;j < m;j ++) {
            char x;
            cin >> x;
            if(x == '*') a[i][j] = 1; 
        }
    }
    for(int i = n - 1;i >= 0;i --) {
        for(int j = m - 1;j >= 0;j --) {
            if(a[i][j] == 0) continue;
            int len = 0;
            while(j > len && j + len + 1 < m && i > len) {
                if(a[i - len - 1][j - len - 1] == 0 || a[i - len - 1][j + len + 1] == 0) break;
                len ++;
            }
            if(len >= k) {
                for (int d = 0; d <= len; d ++) {
                        a[i - d][j - d] = 2;
                        a[i - d][j + d] = 2;
                }
            }
        }
    }
    bool f = 1;
    for(int i = 0;i < n;i ++) {
        for(int j = 0;j < m;j ++) {
            if(a[i][j] == 1){
                f = 0;
            }
        }
    }
    cout << (f ? "YES" : "NO") << "\n";
}
int main() {
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}