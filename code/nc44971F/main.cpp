#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 1e6 + 10, mod = 998244353;

vector<int> prime;
vector<bool> is_prime(MAXN, 1);
void ola(int n) {
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= n; i ++) {
        if(is_prime[i]) {
            prime.push_back(i);
        }
        for(int j = 0; i * prime[j] <= n && j < prime.size(); j ++) {
            is_prime[prime[j] * i] = 0;
            if(! (i % prime[j])) {
                break; 
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ola(MAXN);
    int _ = 1;
    cin >> _;
    while(_ --) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << "24\n";
            continue;
        }
        vector<int> factor(1, 1);
        for(int i = 0; i < 3; i ++) {
            int x = *lower_bound(prime.begin(), prime.end(), factor.back() + n);
            factor.push_back(x);
        }
        ll res = 1;
        for(int i : factor) {
            res *= i;
        }
        cout << res << '\n';
    }
}