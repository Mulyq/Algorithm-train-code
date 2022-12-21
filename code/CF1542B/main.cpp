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
#include <stack>
#include <queue>
#include <bitset>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if(a == 1) {
        cout << (!((n - 1) % b) ? "Yes\n" : "No\n");
        return ;
    } 
    ll s = 1;
    while(n - s >= 0) {
        int tmp = n;
        tmp -= s;
        if(tmp % b == 0) {
            cout << "Yes\n";
            return;
        }
        s *= (ll)a;
    }
    cout << "No\n";
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