#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

void solve() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<char> res;
    while(n) {
        int x = n % 16;
        if(x < 10) res.push_back('0' + x);
        else res.push_back('A' + x - 10);
        n /= 16;
    }
    if(res.size() < 2) res.push_back('0');
    reverse(res.begin(), res.end());
    for(auto i : res) {
        cout << i;
    }
}