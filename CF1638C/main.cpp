#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
vector<int> a;

void solve() {
    int n;
    cin >> n;
    vector<int> st;
    for(int i = 0; i < n; i ++) {
        int a; cin >> a;
		if(!i || a > st.back()) {
            st.push_back(a);
            continue;
        }
        int tmp = st.back();
        while (st.size() && st.back() > a) {
            st.pop_back();
        }
        st.push_back(tmp);
    }
    cout << st.size() << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}