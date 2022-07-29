#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

bool isprime(int x) {
    for(int i = 2; i <= x / i; i ++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = a; i <= b; i ++) {
        bool f = 0;
        for(int j = c; j <= d; j ++) {
            if(isprime(i + j)) {
                f = 1;
            }
        }
        if(!f) {
            cout << "Takahashi";
            return 0;
        }
    }
    cout << "Aoki";

    return 0;
}