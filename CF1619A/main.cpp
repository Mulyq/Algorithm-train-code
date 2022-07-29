#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
void solve() {
        string s;
        cin >> s;
        if(s.size() % 2 == 1){cout << "NO" << endl;return ;}
        for(int i = 0, j = s.size() / 2;j < s.size() ;i ++ ,j ++)
            if(s[i] != s[j]) 
                {cout << "NO" << endl;return ;}
        cout << "YES" << endl;
        return;
}
int main(){
    int T;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}