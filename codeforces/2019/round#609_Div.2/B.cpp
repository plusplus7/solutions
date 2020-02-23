#include <bits/stdc++.h>

using namespace std;

int a[2005], b[2005];
int main()
{
    int n,m;
    scanf("%d%d", &n,&m);
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", b+i);
    }

    sort(a, a+n);
    sort(b, b+n);

    int ans = 0x7fffffff;
    for (int i=0; i<n; i++) {
        int x = b[i] - a[0];
        if (x < 0) {
            x+=m;
        }
        int ok = 1;
        for (int j=0; j<n; j++) {
            if ((a[j]+x)%m != b[(i+j)%n]) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            ans = min(x, ans);
        }
    }

    printf("%d\n", ans);
    return 0;
}
