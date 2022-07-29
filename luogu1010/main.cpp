#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
int n;
void f(int x) {
    if(x == 0) {
        cout << 0;
        return ;
    } else if(x == 1) {
        return ;
    }
    vector<int> a;
    int k = 0;
    while(x) {
        if(x & 1) {
            a.push_back(k);
        }
        k ++;
        x >>= 1;
    }
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i ++) {
        if(a[i] == 1) {
            if(i != a.size() - 1) {
                cout << "2+";
            }else {
                cout << "2";
            }
        }else {
            if(i != a.size() - 1) {
                cout << "2(";
                f(a[i]);
                cout << ")+";
            } else {
                cout << "2(";
                f(a[i]);
                cout << ")";   
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    f(n);
    return 0;
}