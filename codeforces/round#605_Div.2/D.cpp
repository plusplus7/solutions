
#include <bits/stdc++.h>
using namespace std;

int n, a[200005], ia[200005], da[200005];
int main(){
    scanf("%d", &n);
    int ans = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
        if (i == 0 || a[i-1] >= a[i]){
            ia[i] = 1;
        } else {
            ia[i] = ia[i-1]+1;
        }
        ans = max(ia[i], ans);
    }
    for (int i=n-1; i>=0; i--) {

        if (i == n-1 || a[i+1] <= a[i]){
            da[i] = 1;
        } else {
            da[i] = da[i+1]+1;
        }
        ans = max(da[i], ans);
    }
    for (int i=1; i<n-1; i++) {
        if (a[i-1] < a[i+1]) {
            ans = max(ia[i-1]+da[i+1], ans);
        }
    }
    printf("%d\n", ans);
}
