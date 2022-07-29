#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < i; j ++) {
            for(int k = j + 1; k < i; k ++) {
                if(i != j && j != k) {
                    if(a[i] == a[j] + a[k]) {
                        if(!mp[a[i]]) {
                            mp[a[i]] = 1;
                            res ++;
                        }
                    }
                }
            }
        }
    }
    cout << res << '\n';
    return 0;
}