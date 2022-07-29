#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for(int i = 1; i < n; i ++) {
        if(s[i] == s[0]) {
            cout << "Wrong  Answer";
            return 0;
        }
    }
    cout << "Correct";
    return 0;
}