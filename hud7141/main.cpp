#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5+ 10, mod = 998244353;
int n, m;
bool is_prime[MAXN];
vector<int> prime;
void ola() {
    memset(is_prime, 1, sizeof is_prime);
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i < 2e5 + 7; i ++) {
        if(is_prime[i]) {
            prime.push_back(i);
        }
        for(int j = 0; i * prime[j] <= 2e5 + 7 && j < prime.size(); j ++) {
            is_prime[prime[j] * i] = 0;
            if(! (i % prime[j])) {
                break;
            }
        }
    }
}
PII node[MAXN];
struct dis{
    int s, a, b;
    bool operator< (const dis &a) const {
        return s < a.s;
    }
};
void solve() {
    cin >> n >> m;
    bitset<2020> cm[2020];
    for(int i = 0; i < n; i ++) {
        cin >> node[i].first >> node[i].second;
        cm[i].reset();
        cm[i].reset();
    }
    vector<dis> D;
    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            D.push_back({ abs(node[i].first - node[j].first) + abs(node[i].second - node[j].second), i ,j});
        }
    }
    sort(D.begin(), D.end());

    int res = 0;
    for(auto it : D) {
        if(is_prime[it.s]) {
            res += (cm[it.a] ^ cm[it.b]).count();
        }
        cm[it.a][it.b] = 1;
        cm[it.b][it.a] = 1;
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ola();
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}