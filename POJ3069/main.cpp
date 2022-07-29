#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); int R, n;
    while(cin >> R >> n) {
        if(R == -1) break;
        vector<int> a(n);
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a.begin(), a.end());
        int res = 0;
        int i = 0;
        while(i < n) {
            int s = a[i ++];
            while(i < n && a[i] <= s + R) i ++;
            int p = a[-- i];
            while(i < n && a[i] <= p + R) i ++;
            res ++;
        }
        cout << res << '\n';
    }
    return 0;
}