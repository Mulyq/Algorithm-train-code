#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10, mod = 1e9 + 7;
typedef vector<vector<int>> mat;
mat mul(mat &A, mat &B) {
    int n = A.size(), t = A[0].size(), m = B[0].size();
    mat C(A.size(), vector<int> (B[0].size()));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            for(int k = 0; k < t; k ++) {
                C[i][j] = (1ll * C[i][j] + 1ll * A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}
mat qpow(mat &A, ll k) {
    int n = A.size();
    mat res(n, vector<int> (n));
    for(int i = 0; i < n; i ++) {
        res[i][i] = 1;
    }
    while(k) {
        if(k & 1) {
            res = mul(res, A);
        }
        A = mul(A, A);
        k >>= 1;
    }
    return res;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    mat A(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> A[i][j];
        }
    }
    mat res = qpow(A, k);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <n ; j ++ ) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}