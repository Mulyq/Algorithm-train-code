#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, mod = 998244353;
const int MAXN =55556; 
vector<int> prime;
vector<bool> is_prime(MAXN, 1);
void solve() {
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= MAXN; i ++) {
        if(is_prime[i]) {
            prime.push_back(i);
        }
        for(int j = 0; i * prime[j] <= MAXN && j < prime.size(); j ++) {
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
    solve();
    int n;
    cin >> n;
    for(int i = 0; i < prime.size() && n; i ++) {
        if(prime[i] % 10 == 1) {
            cout << prime[i] << ' ';
            n --;
        }
    }
}