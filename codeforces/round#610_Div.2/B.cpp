#include <bits/stdc++.h>
using namespace std;
int n, p, k;
int a[200005];
int c[200005];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &p, &k);
        for (int i=0; i<n; i++) {
            scanf("%d", a+i);
        }
        sort(a, a+n);
        int ans = n;
        for (int i=0; i<n; i++) {
            if (i < 2) {
                c[i] = a[i];
            } else {
                c[i] = a[i] + c[i-2];
            }
            if (c[i] > p) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
