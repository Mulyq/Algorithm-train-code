#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    deque<int> v(n);
    int cnt = 0;
    for(int i = 0; i < n; i ++) { 
        cin >> v[i];
        if(v[i] == 1) cnt ++;
    }
    if(cnt != 1) {
        cout << "No\n";
    } else {
        while (v[0] != 1) {
            v.push_back(v.front());
            v.pop_front();
        }
        for(int i = 1; i < n; i ++) {
            if(v[i] > v[i - 1] && v[i] != v[i - 1] + 1) {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    }
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