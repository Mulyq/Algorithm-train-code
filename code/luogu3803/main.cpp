#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int MAXN = 2e6 + 10;
int R[MAXN];
void fft(vector<complex<double>> &A,int type){
    int n = A.size();
    for(int i = 0; i < n; i ++) {
        if(i < R[i]) swap(A[i], A[R[i]]);
    }
    for(int mid = 1; mid < n; mid <<= 1) {
        complex<double> wn(cos(pi / mid), type * sin(pi / mid));
        for(int len = mid << 1, pos = 0; pos < n; pos += len){
            complex<double> w(1, 0);
            for(int k = 0; k < mid; k ++, w = w * wn) {
                complex<double> x = A[pos + k];
                complex<double> y = w * A[pos + mid + k];
                A[pos + k] = x + y;
                A[pos + mid + k] = x - y;
            }
        }
    }
}
void solve(){
    int n1, n2, n = 1, pr = 0;
    cin >> n1 >> n2;
    while(n <= n1 + n2) {
        n <<= 1, pr ++;
    }
    for(int i = 0; i < n; i ++) {
        R[i] = (R[i / 2] >> 1) | ((i & 1) << (pr - 1));
    }
    vector<complex<double>> a(n), b(n);
    for(int i = 0; i <= n1; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i <= n2; i ++) {
        cin >> b[i];
    }
    fft(a, 1);
    fft(b, 1);
    for(int i = 0; i < n; i ++) {
        a[i] *= b[i];
    }
    fft(a, -1);
    for(int i = 0; i <= n1 + n2; i ++) {
        cout << (int)(a[i].real() / n + 0.5) << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
