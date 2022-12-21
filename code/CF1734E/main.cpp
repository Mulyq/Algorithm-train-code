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
    vector<int> b(n);
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    vector<vector<int>> v(n, vector<int> (n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            v[i][j] = (i * j) % n;
        }
    }
    for(int i = 0; i < n; i ++) {
        int t = (b[i] - v[i][i] + n) % n;
        for(int j = 0; j < n; j ++) {
            (v[i][j] += t) %= n;
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}