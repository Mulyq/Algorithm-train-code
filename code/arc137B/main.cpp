#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] == 0) {
            a[i] = - 1;
        }
    }
    int maxx = 0, minx = INF;
    int temp1 = 0, temp2 = 0;
    for(int i = 0; i < n; i ++) {
        temp1 += a[i];
        if(temp1 < 0) {
            temp1 = 0;
        }
        temp2 += a[i];
        if(temp2 > 0) {
            temp2 = 0;
        }
        maxx = max(maxx, temp1);
        minx = min(minx, temp2);
    }
    cout << maxx - minx + 1 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}