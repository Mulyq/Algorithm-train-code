#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int c = 0, r = n;
    if(n == 1) {
        cout << 0 << ' ' << 1 << '\n';
        return;
    }
    for(int i = 0; i < n - 1; i ++) {
        if(s[i] == '(' && s[i + 1] == ')') {
            c ++, r -= 2;
            i ++;
        } else if(s[i] == '(' && s[i + 1] == '(') {
            c ++, r -= 2;
            i ++;
        } else if(s[i] == ')' && s[i + 1] == ')') {
            c ++, r -= 2;
            i ++;
        } else{
            int j = i + 1;
            for(; j < n; j ++) {
                if(s[j] == ')') {
                    c ++, r -= j - i + 1;
                    break;
                }
            }
            i = j;
        }
    }
    cout << c << ' ' << r << '\n';
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