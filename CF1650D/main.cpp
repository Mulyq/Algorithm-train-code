#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    deque<int> a(n);
    vector<int> res(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    while(a.size()) {
        int k = 0;
        while(a.back() != a.size()) {
            a.push_back(a.front());
            a.pop_front();
            k ++;
        }
        res[a.size() - 1] = k;
        a.pop_back();
    }
    for(int i = 0; i < n; i ++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
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