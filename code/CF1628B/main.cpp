#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    set<string> S;
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i ++) {
        bool ok = 1;
        for(int j = 0, k = v[i].size() - 1; j < k; j ++, k --) {
            if(v[i][j] != v[i][k]) {
                ok = 0;
            }
        }
        if(ok) {
            cout << "YES\n";
            return;
        }
        if(v[i].size() == 3) {
            string a = v[i];
            string b = v[i];
            S.insert(a);
            string x = b;
            // x.pop_back();
            // S.insert(x);
            b.erase(b.begin(), b.begin() + 1);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            if(S.find(a) != S.end() || S.find(b) != S.end()) {
                cout << "YES\n";
                return ;
            }
        } else {
            string a = v[i];
            S.insert(a);
            reverse(a.begin(), a.end());
            if(S.find(a) != S.end()) {
                cout << "YES\n";
                return ;
            }
            for(int i = 0; i < 26;i ++) {
                string x = a;
                x += 'a' + i;
                if(S.find(x) != S.end()) {
                    cout << "YES\n";
                    return ;
                }
            }
        }
    }
    cout << "NO\n";
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