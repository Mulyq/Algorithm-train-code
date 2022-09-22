#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(6);
    for(int &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    vector<int> sub(5);
    for(int i = 0; i < 5; i ++) {
        sub[i] = a[i + 1] - a[0];
    }
    int n;
    cin >> n;
    vector<int> b(n);
    for(int &i : b) {
        cin >> i;
    }
    sort(b.begin(), b.end());
    
}