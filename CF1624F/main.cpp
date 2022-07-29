#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int l = 1, r = n;
    while(l < r) {
        int mid = l + r >> 1;
        cout << "+ " << mid << '\n';
        int check ;
        check = fflush(stdout);
        if(check == 1) 
            r = mid;
        else l = mid + 1;
    }
    cout << "! " << n - l << '\n';
    return 0;
}