#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
vector<int> add(vector<int> A, vector<int> B) {
    int t = 0;
    vector<int> res;
    for(int i = 0; i < A.size() || i < B.size(); i ++) {
        if(i < A.size()) {
            t += A[i];
        }
        if(i < B.size()) {
            t += B[i];
        }
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}
vector<int> mul(vector<int> A, int q) {
    vector<int> res;
    int r = 0;
    for(int i = 0; i < A.size() || r; i ++) {
        if(i < A.size()) r += A[i] * q;
        res.push_back(r % 10);
        r /= 10;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sum(1, 1);
    vector<int> res(1, 0);
    for(int i = 1; i <= n; i ++) {
        sum = mul(sum, i);
        res = add(res, sum);
    }
    for(int i = res.size() - 1; i >= 0; i --) {
        cout << res[i];
    }
    return 0;
}