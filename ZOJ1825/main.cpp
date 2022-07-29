#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    set<string> S;
    vector<string> str;
    string s;
    while(cin >> s) {
        str.push_back(s);
        S.insert(s);
    }
    for(auto x : str) {
        if(x.size() == 1) continue;
        for(int i = 1; i < x.size(); i ++) {
            string a, b;
            a = b = "";
            for(int j = 0; j < i; j ++) {
                a += x[j];
            }
            for(int j = i; j < x.size(); j ++) {
                b += x[j];
            }
            if(S.find(a) != S.end() && S.find(b) != S.end()) {
                cout << x << '\n';
                break;
            }
        }
    }
    return 0;
}