#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i ++) {
        cout << a[i].second <<' ';
    }
    cout << '\n';
    double res = 0;
    for(int i = 0; i < n; i ++) {
        res += (n - i - 1) * a[i].first;
    }
    printf("%.2lf", res / n);
}
int main(){
    int _ = 1;
    //cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}