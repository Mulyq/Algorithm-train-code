#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

void solve() {

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string rec = "", temp;
    while(cin >> temp) {
        rec += temp;
    }
    int a, b;
    a = b = 0;
    for(int i = 0; i < rec.size(); i ++) {
        if(rec[i] == 'E') {
            break;
        }
        if(rec[i] == 'W') {
            a ++;
        } else {
            b ++;
        }
        if((a >= 11 || b >= 11) && abs(a - b) >= 2) {
            cout << a << ':' << b << '\n';
            a = b = 0;
        }
    }
    cout << a << ':' << b << '\n';
    cout << '\n';
    a = b = 0;
    for(int i = 0; i < rec.size(); i ++) {
        if(rec[i] == 'E') {
            break;
        }
        if(rec[i] == 'W') {
            a ++;
        } else {
            b ++;
        }
        if((a >= 21 || b >= 21) && abs(a - b)  >= 2) {
            cout << a << ':' << b << '\n';
            a = b = 0;
        }
    }
    cout << a << ':' << b << '\n';
    a = b = 0;

    return 0;
}