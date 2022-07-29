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
    sort(a.begin(), a.end());
    ll sumr, sumb, cntr, cntb;
    sumr = sumb = cntr = cntb = 0;
    sumb = a[0]; cntb = 1; 
    for(int i = 1, j = n - 1; i < j; i ++, j --) {
        if(sumr > sumb) {
            cout << "Yes\n";
            return;
        }
        sumb += a[i];
        sumr += a[j];
    }
    if(sumr > sumb) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;
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