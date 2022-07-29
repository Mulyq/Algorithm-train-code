#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<char, PII> mp;
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        char s;
        int n, m;
        cin >> s >> n >> m;
        mp[s] = {n, m};
    }
    string str;
    while (cin >> str) {
        stack<PII> S;
        bool f = 1;
        int res = 0;
        for(int i = 0; i < str.size(); i ++) {
            if(str[i] != ')' && str[i] != '(') {
                S.push(mp[str[i]]);
            } else if(str[i] == ')') {
                PII a = S.top();
                S.pop();
                PII b = S.top();
                S.pop();
                if(b.second != a.first) {
                    cout << "error\n";
                    f = 0;
                    break;
                } else {
                    res += b.first * a.second  *a.first;   
                    S.push({b.first, a.second});
                }
            }
        }
        if(f) {
            cout << res <<'\n';
        }
    }
    return 0;
}