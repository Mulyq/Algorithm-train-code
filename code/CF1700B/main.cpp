#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 10;

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;//表示借位
    for(int i = 0; i < A.size(); i ++) {
		t = A[i] - t;
        if(i < B.size() ) t -= B[i];
        C.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
void solve() {
    int n;
    string s;
    string all;
    cin >> n >> s;
    if(s[0] == '9') {
        for(int i = 0; i <= n ; i ++) {
            all += '1';
        }
    } else {
        for(int i = 0; i <= n; i ++) {
            if(i == 0 || i == n) {
                all += '1';
            } else {
                all += '0';
            }
        }
    }
    vector<int> A, B;
    for(int i = 0; i < n; i ++) {
        A.push_back(s[n - i - 1] - '0');
    }
    for(int i = 0; i <= n; i ++) {
        B.push_back(all[i] - '0');
    }
    vector<int> res = sub(B, A);
    for(int i = n - 1; i >= 0; i --) {
        cout << res[i];
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_ --) {
        solve();
    }
    return 0;
}