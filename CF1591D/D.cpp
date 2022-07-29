#include<bits/stdc++.h>
#define ll long long
const int N = 5e5 + 10;
int a[N],tmp[N];
ll merge_sort(int q[],int l ,int r) {
    if(l >= r) return 0;
    int mid = l + r >> 1;
    ll rec = merge_sort(q,l,mid) + merge_sort(q,mid + 1,r);
    int i = l,j = mid + 1, k = 0;
    while(i <= mid && j <= r) {
        if(q[i] <= q[j]) {
            tmp[k ++] = q[i ++];
        }
        else {
            tmp[k ++] = q[j ++];
            rec += mid - i + 1;
        }
    }
    while(i <= mid) {
        tmp[k ++] = q[i ++];
    }
    while(j <= r) {
        tmp[k ++] = q[j ++];
    }
    for(int i = l,k = 0;i <= r;i ++,k ++) {
        q[i] = tmp[k];
    }
    return rec;
}
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        int n;
        bool f = 1;
        scanf("%d",&n);
        for(int i = 0;i < n;i ++) {
            scanf("%d",&a[i]);
        }
        ll ba = merge_sort(a,0,n - 1);
        if(ba % 2 != 0) {
            f = 0;
        }
        for(int i = 1;i < n;i ++) {
            if(a[i] == a[i - 1]) {
                f = 1;
            }
        }
        printf(f? "YES\n" : "NO\n");
    }
}