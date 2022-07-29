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
    set<int> s;
    for(int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size();
    return 0;
}