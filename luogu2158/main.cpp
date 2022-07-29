#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e7 + 10;
int prime[MAXN];
bool is_prime[MAXN];
int phi[MAXN];
int p = 0;
void solve(int n) {
    memset(is_prime, 1, sizeof is_prime);
    is_prime[0] = is_prime[1] = 0;
    phi[1] = 1;
    for(int i = 2; i <= n; i ++) {
        if(is_prime[i]) {
            prime[p ++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < p && prime[j] * i < MAXN; j ++) {
            is_prime[i * prime[j]] = 0;
            if(i % prime[j]) {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            } else {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
        }
    }
}
ll all[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    ll res = 0;
    all[1] = p;
    for(int i = 0; i < p; i ++) {
        int t = n / prime[i];
        all[t + 1] --;
    }
    for(int i = 1; i <= n; i ++) {
        all[i] += all[i - 1]; 
    }
    for(int i = 1; all[i]; i ++) {
        if(i == 1) res += phi[i] * all[i];
        else res += 2 * (phi[i] * all[i]);
    }
    cout << res << '\n';
    return 0;
}