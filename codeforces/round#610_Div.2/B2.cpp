#include <bits/stdc++.h>
using namespace std;
int n, p, k;
int a[200005];
int c[200005];
int main()
{
    int t,cx;
    cx=1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &p, &k);
        for (int i=1; i<=n; i++) {
            scanf("%d", a+i);
        }
        sort(a+1, a+n+1);
        int ans = 0;
        a[0] =0;
        c[0] = 0;
        for (int i=1; i<=n; i++) {
            if (i < k) {
                c[i] = a[i] + c[i-1];
            } else if (i == k) {
                c[i] = a[i];
            } else {
                c[i] = a[i] + c[i - k];
            }
       //     printf("->%d %d %d %d\n", i, c[i], a[i], c[i-k]);
            if (c[i] <=p) {
                ans = max(i, ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
