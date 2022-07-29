#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    cin >> n ;
    vector<int> a(n + 1);
    for(int i = 0; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i <= n; i ++) {
        int b = n - i, k = a[i];
        if(i == 0) {
            if(k > 0) {
                if(k == 1) {
                    cout << 'x';
                } else {
                    cout << k << 'x';
                }
            } else {
                if(k == -1) {
                    cout << "-x";
                } else {
                    cout << k << 'x';
                }
            }
            if(b > 1) {
                cout << "^" << b;
            }
        } else {
            if(k) {
                if(b == 0) {
                    if(k > 0) {
                        cout << '+' << k;
                    } else {
                        cout << k;
                    }
                } else {
                    if(k > 0) {
                        if(k == 1) {
                            cout << "+x";
                        } else {
                            cout << '+' << k << 'x';
                        }
                    } else {
                        if(k == -1) {
                            cout << "-x";
                        } else {
                            cout << k << 'x';
                        }
                    }
                    if(b > 1) {
                        cout << "^" << b;
                    }
                }
            }
        }

    }
    return 0;
}