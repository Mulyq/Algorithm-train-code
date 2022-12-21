#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

void solve() {
	int n;
    ll sum = 0;
    cin >> n;
    vector<int> b(n), a(n);
    for(auto & x : b) {
        cin >> x;
        sum += x;
    }
    if(sum % ((n + 1) * n / 2)) {
        cout << "NO\n";
        return ;
    }
    sum /= ((n + 1) * n / 2);
    for(int i = 0;i < n;i ++) {
        a[i] = sum - (b[i] - b[(i + n - 1) % n]);
        if(a[i] <= 0 || a[i] % n) {
			cout << "NO\n";
        	return ;
        }
        a[i] /= n;
    }
    cout << "YES\n";
    for(auto x : a) {
		cout << x << ' ';
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}