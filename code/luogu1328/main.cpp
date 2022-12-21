#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;
const int wl[5][5] = {{0, 0, 1, 1, 0}, {1, 0, 0, 1, -0}, {0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {1, 1 ,0, 0 ,0} };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k , a, b;
    cin >> k >> a >> b;
    vector<int> A, B;
    for(int i = 0; i < a; i ++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < b; i ++) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
    int r1, r2;
    r1 = r2 = 0;
    for(int i = 0; i < k ; i ++) {
        int x = A[i % a], y = B[i % b];
        r1 += wl[x][y];
        r2 += wl[y][x];
    }
    cout << r1 << ' ' << r2;
    return 0;
}