#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i ++) cin >> a[i];
    deque<int>Q;
    for(int i = 0;i < n;i ++) {
        if(Q.empty() || Q.front() >= a[i]) Q.push_front(a[i]);
        else Q.push_back(a[i]);
    }
    while(!Q.empty()) {
        cout << Q.front() << ' ';
        Q.pop_front();
    }
    cout << '\n';
}
int main() {
    int T;
    cin >> T;
    while( T --) solve();
    return 0;
}