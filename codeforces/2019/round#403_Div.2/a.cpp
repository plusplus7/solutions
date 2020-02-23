#include <cstdio>
#include <cstring>
int a[100006];
int main()
{
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    int ans = 0;
    int cur = 0;
    n<<=1;
    while (n--) {
        int t;
        scanf("%d", &t);
        if (a[t] == 0) {
            a[t]++;
            cur ++;
        } else {
            a[t]--;
            cur--;
        }
        ans = ans<cur?cur:ans;
    }
    printf("%d\n", ans);
}
