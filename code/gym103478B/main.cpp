#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 1e9 + 7, MAXN = 2e5 + 10, mod = 998244353;
vector<string> tab = {
"H","HE","LI","BE","B","C","N","O","F","NE",
"NA","MG","AL","SI","P","S","CL","AR","K","CA"};
set<string> S;
void dfs(string &s, int p) {
    if(p >= s.size()) {
        cout << "YES\n";
        exit(0);
    }
    string x = "";
    x += s[p];
    if(S.find(x) != S.end()) {
        dfs(s, p + 1);
    }
    if(p < s.size() - 1) {
        x += s[p + 1];
        if(S.find(x) != S.end()) {
            dfs(s, p + 2);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(string i : tab) {
        S.insert(i);
    }
    string s;
    cin >> s;
    dfs(s, 0);
    cout << "NO\n";
}