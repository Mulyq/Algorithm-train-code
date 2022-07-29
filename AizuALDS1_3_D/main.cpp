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
#include <tuple>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

void solve() {
    string s;
    cin >> s;
    stack<int> idx;
    stack<PII> sum;
    int res = 0;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '\\') idx.push(i);
        else if(s[i] == '/' && !idx.empty()) {
            int l = idx.top(), r = i;
            idx.pop();
            res += r - l;
            int tmpsum = r - l;
            while(!sum.empty() && l < sum.top().first) {
                tmpsum += sum.top().second;
                sum.pop();
            }
            sum.push({i, tmpsum});
        }
    }
    vector<int> rres;
    while(!sum.empty()) {
        rres.push_back(sum.top().second);
        sum.pop();
    }
    reverse(rres.begin(), rres.end());    
	cout << res << '\n' << rres.size();
    for(auto it : rres) {
        cout << ' ' <<it;
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}