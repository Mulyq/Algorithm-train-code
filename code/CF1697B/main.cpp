#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for(int i= 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
    }
    while(q --) {
        int x, y;
        cin >> x >> y;
        cout << - a[n - x] + a[n - x +  y] << '\n';
    }
    return 0;
}