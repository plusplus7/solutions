#include <bits/stdc++.h>
using namespace std;

int b[200005];
int ans[200005];
struct T {
    int c;
    int n;
};
T a[200005];
bool cmp(T a, T b) {
    return a.n < b.n;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", b+i);
    }
    sort(b, b+n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i].n);
        a[i].c = i;
    }
    sort(a, a+n, cmp);
    for (int i=0; i<n; i++) {
        ans[a[i].c] = b[n-i-1];
    }
    for (int i=0; i<n-1; i++) {
        printf("%d ", ans[i]);
    }
        printf("%d\n", ans[n-1]);
    return 0;
}
