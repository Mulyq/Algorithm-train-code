#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    map<string ,int> mp;
    vector<string> str;
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        str.push_back(s);
        mp[s] = 1;
        if(s.size() == 1) {
            cout << "YES\n";
            return ;   
        }
        string s1, s2, s3 ,s4;
        s1 = s2 = s3 = s4;
        reverse(s1.begin(),s1.end());
        s2.pop_back();
        reverse(s2.begin(),s2.end());
        s3.pop_back();
        reverse(s3.begin(),s3.end());
        reverse(s4.begin(),s4.end());
        if(mp[s1] || mp[s2] || mp[s3] || mp[s4]) {cout << "YES\n" ;return ;}

    }
    cout << "NO\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}