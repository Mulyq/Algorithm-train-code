#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int i = 0;
    while(a[i] == 1) {
        i ++;
    }
    i --;
    int j = n - 1;
    while (a[j] == 1) { 
        j --; 
    }
    j ++;
    cout << max(j - i, 0)  << '\n'; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}