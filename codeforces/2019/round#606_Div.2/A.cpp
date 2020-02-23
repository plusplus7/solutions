#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q;
    scanf("%d", &q);
    while (q--) {
        int ans = 0, n;
        scanf("%d", &n);
        for (int i=1; i<=9; i++) {
            long long t = (long long)i, tn = (long long)n;
            while (t <= tn) {
                ans ++;
                t*=10ll;
                t+=(long long)i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
