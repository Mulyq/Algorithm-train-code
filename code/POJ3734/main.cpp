#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10, mod = 10007;
typedef vector<vector<int> > mat;
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
    int n;
    scanf("%d", &n);
    mat A(3, vector<int> (3));
    A[0][0] = A[1][0] = A[1][1] = A[1][2] = A[2][2] = 2;
    A[0][1] = A[2][1] = 1;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mat temp = A;
        mat res = qpow(temp, x);
        printf("%d\n", res[0][0] % mod);
    }
}
int main() {
    solve();
    return 0;
}