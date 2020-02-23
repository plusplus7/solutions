#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int a[200005], b[200005], c[200005];
int main() {
    int n;
    int x = 1900;
    int s = 0x7fffffff;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d%d", c+i, b+i);
        a[i] = x;
        if (b[i] == 2) {
            s = s > a[i] ? a[i] : s;
        }
        x -= c[i];
    }
    int g = s-1;
    for (int i=0; i<n; i++) {
        if (b[i] == 1) {
            if (g < a[i]) {
                printf("Impossible\n");
                return 0;
            }
        }
    }
    if (g == 0x7fffffff - 1) {
        printf("Infinity\n");
        return 0;
    }
    int ans = g;
    for (int i=0; i<n; i++) {
        ans = g > ans? g:ans;
        g = g + c[i];
    }
    ans = g > ans? g:ans;
    printf("%d\n", g);
    return 0;
}
