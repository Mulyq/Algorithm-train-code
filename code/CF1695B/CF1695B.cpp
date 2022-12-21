#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mm = 0, jj = 1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(i % 2 == 0) {
           if(a[i] < a[mm]) mm = i;
        }
        else {
            if(a[i] < a[jj]) jj = i;
        }
    }
    if(n % 2 == 1) {
        cout << "Mike\n";
    } else {
        if(a[jj] != a[mm]) {
            if(a[jj] > a[mm])
                cout << "Joe\n";
            else 
                cout << "Mike\n";
        } else {
            if(jj < mm)
                cout << "Mike\n";
            else
                cout << "Joe\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}