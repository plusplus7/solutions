#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, d;
        scanf("%d%d", &n, &d);
        int ans = 0;
        for (int i=0; i<n; i++) {
            int t;
            scanf("%d", &t);
            if (d <= 0) {
                continue;
            }
            if (d > t*i) {
                ans += t;
                d -= t*i;
            } else {
                ans += d/i;
                d = 0;
            }
        }
        printf("%d\n", ans);
    }
}