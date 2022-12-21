#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
string s, t, k;
int len = 0;
vector<char> res, st;
void dfs(int x, int y) {
    if(x == len && y == len) {
        if(k == t) {
            for(auto x : res) {
                cout << x << ' ';
            }
            cout << '\n';
        }
        return ;
    }
    if(x < len) {
        st.push_back(s[x]);
        res.push_back('i');
        dfs(x + 1, y);
        st.pop_back();
        res.pop_back();
    }
    if(y < x) {
        res.push_back('o');
        k += st.back();
        st.pop_back();
        dfs(x, y + 1);
        st.push_back(k.back());
        res.pop_back();
        k.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    while(cin >> s >> t) {
        len = s.size();
        cout << "[\n";
        dfs(0, 0);
        cout << "]\n";
    }
    return 0;
}