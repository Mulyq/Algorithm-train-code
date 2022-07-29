#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
string get(string s) {
    string res;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] >= 'A' && s[i] < 'a') {
            s[i] = s[i] - 'A' + 'a';
            res += s[i];
        } else {
            res += s[i];
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int place = - 1, sum = 0;
    
    string t, word;
    cin >> t;
    t = get(t);
    getline(cin, word);
    getline(cin, word);
    string temp = "";
    for(int i = 0; i < word.size(); i ++) {
        if(word[i] == ' ') {
            temp = get(temp);
            if(temp == t) {
                sum ++;
                if(place == - 1) {
                    place = i - temp.size();
                }
            }
            temp = "";
        } else {
            temp += word[i];
        }
    }
    if(place == - 1) {
        cout << place << '\n';
    } else {
        cout << sum << ' ' << place << '\n';
    }
    return 0;
}