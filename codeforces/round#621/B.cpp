#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x;
        scanf("%d%d", &n, &x);
        int ma = -1, xm = 0;
        for (int i=0; i<n; i++) {
            int t;
            scanf("%d", &t);
            ma = max(t, ma);
            if (t == x) {
                xm = 1;
            }
        }
        if (xm == 1) {
            printf("1\n");
            continue;
        }
        if (ma > x) {
            printf("2\n");
            continue;
        }
        if (x%ma == 0) {
            printf("%d\n", x/ma);
        } else {
            printf("%d\n", x/ma+1);
        }
    }
}