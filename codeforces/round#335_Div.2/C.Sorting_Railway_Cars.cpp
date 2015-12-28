#include <cstdio>

int a[100005];

int main()
{
    int n, t;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &t);
        a[t] = i;
    }
    int ans = 1;
    int cnt = 1;
    for (int i=2; i<=n; i++) {
        if (a[i] > a[i-1]) {
            cnt++;
            ans = ans < cnt ? cnt : ans;
        } else {
            cnt = 1;
        }
    }
    printf("%d\n", n-ans);
    return 0;
}
