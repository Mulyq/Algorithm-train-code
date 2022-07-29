#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int ask(int c) {
    cout << "+ " << c << '\n'; 
    int x;
    cin >> x;
    return x;
}
int main() {
    int n;
    cin >> n;
    int l = 1, r = n;
    int p = 0;
    while(l != r - 1) {
        int m = l + r >> 1;
        int d = ask(n - 1);
        if(p != d) l = m;
        else r = m;
        l = (l + n - m) % n;
        r = (r + n - m) % n;
        if(r == 0) r = n;
        p = d;
    }
    cout << "! " << p * n + l << '\n';
}