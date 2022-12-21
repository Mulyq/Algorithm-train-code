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
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

void solve() {
    int a[3];
    for(int i = 0;i < 3;i ++) {
        cin >> a[i];
    }
    sort(a,a + 3);
    if(a[2] == a[0] + a[1]) cout << "YES\n";
    else if(a[0] % 2 == 0 && a[1] == a[2]) cout << "YES\n";
    else if(a[2] % 2 == 0 && a[1] == a[0]) cout << "YES\n";
    else cout<<"NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}