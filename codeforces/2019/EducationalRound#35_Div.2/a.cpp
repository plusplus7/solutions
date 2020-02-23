#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    int n, minm;
    minm = 2000000000;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
        minm = minm < a[i] ? minm : a[i];
    }
    int md = -1, ans = 2000000000;
    for (int i=0; i<n; i++) {
        if (a[i] == minm) {
            if (md != -1 && i-md < ans) {
                ans = i-md;
            }
            md = i;
        }
    }

    printf("%d\n", ans);
    return 0;
}