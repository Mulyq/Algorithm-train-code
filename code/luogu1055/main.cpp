#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    string s;
    cin >> s;
    vector<int> a;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] >= '0' && s[i] <= '9') {
            a.push_back(s[i] - '0');
        } else if(s[i] == 'X') {
            a.push_back(10);
        }
    }
    int sum = 0;
    for(int i = 0; i < a.size() - 1; i ++) {
        sum += a[i] * (i + 1);
    }
    sum %= 11;
    if(sum == a.back()) {
        cout << "Right\n";
    } else {
        if(sum == 10) {
            s.back() = 'X';
        } else {
            s.back() = '0' + sum;
        }
        cout << s << '\n';
    }
    return 0;
}