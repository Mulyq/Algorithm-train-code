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
    int n;
    cin >> n;
    int idx = 0;
    vector<int> a;
    vector<PII> cnt;
    for(int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        a.push_back(t);
        if(cnt.empty() || cnt.back().first != t) {
            cnt.push_back({t, 1});
        }
        else {
            cnt.back().second ++;
            if(cnt.back().second == t) {
                for(int i = 0; i < t; i ++) {
                    if(a.empty()) break;
                    a.pop_back();
                }
                cnt.pop_back();
            } 
        }
        cout << a.size() << '\n';
    }
    return 0;
}