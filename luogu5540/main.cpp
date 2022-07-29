#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
string s;
const int M = 1e8 + 10;
int cnt = 0;
int primes[M];
bool val[M];
inline void ola(int n) {
    val[1] = val[0] = 1;
    for (int i = 2; i <= n; i ++) {
        if (val[i] == 0) primes[cnt ++] = i;//将质数存到primes中
		//要确保质数的第i倍是小于等于n的。
        for (int j = 0; primes[j] <= n / i; j ++) {
            val[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
bool isPrime(int x) {
    if(x <= 1) return 0;
    for(int i = 2; i <= x / i; i ++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
bool isr(int x) {
    if(x % 100 != 0) {
        if(x % 4 == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if(x % 400 == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}
int res = 0;
int dd, mm, yy;
void dfs(int x) {
    if(x <= 3) {
        if(s[x] == '-') {
            for(int i = 0; i <= 9; i ++) {
                yy = yy * 10 + i;
                dfs(x + 1);
                yy /= 10;
            }
        } else {
            yy = yy * 10 + s[x] - '0';
            dfs(x + 1);
            yy /= 10;
        }
    } else if(x <= 5) {
        if(s[x] == '-') {
            for(int i = 0; i <= 9; i ++) {
                mm = mm * 10 + i;
                if(mm <= 12) {
                    dfs(x + 1);
                }
                mm /= 10;
            }
        } else {
            mm = mm * 10 + s[x] - '0';
            dfs(x + 1);
            mm /= 10;
        }
    } else if(x <= 7){
        if(s[x] == '-') {
            for(int i = 0; i <= 9; i ++) {
                dd = dd * 10 + i;
                if(dd <= 31) {
                    dfs(x + 1);
                }
                dd /= 10;
            }
        } else {
            dd = dd * 10 + s[x] - '0';
            dfs(x + 1);
            dd /= 10;
        }
    } else {
        if(yy == 0 || mm > 12 || mm == 0 || dd == 0) return;
        if(((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && dd > 31) || ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30)) return;
        if(mm == 2) {
            if(isr(yy) && dd > 29) return;
            else if(!isr(yy) && dd > 28) return;
        }

        if(!val[mm * 100 + dd] && !val[dd]) {
            if(yy * 10000 + mm * 100 + dd <= 1e8) {
                if(!val[yy * 10000 + mm * 100 + dd]) {
                    // cout << yy * 10000 + mm * 100 + dd << '\n';
                    res ++;
                }
            } 
            else {
                if(isPrime(yy * 10000 + mm * 100 + dd)) {
                    // cout << yy * 10000 + mm * 100 + dd << '\n';
                    res ++;
                }
            }
        }
        return;
    }
}
void solve() {
    
    dd = yy = mm = 0;
    res = 0;
    cin >> s;
    // if(s == "--------") {
    //     cout << "55157\n";
    //     return ;
    // }
    dfs(0);
    cout << res << '\n';
}
int main(){
    // double st = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);
    ola(1e8);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    // double ed = clock();
    // cout << ed - st << '\n';
    return 0;
}