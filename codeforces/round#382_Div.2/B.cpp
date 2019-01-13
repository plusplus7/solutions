#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int a[100006];
int n, n1, n2;

long long maxll(long long a, long long b) {
    return a > b?a: b;
}

int main() {
    scanf("%d%d%d", &n, &n1, &n2);
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
    }
    sort(a, a+n);
    long long ans = 0l;
    long long ln1 = (long long)n1;
    long long ln2 = (long long)n2;
    {
        long long s1, s2;
        int c = n-1;
        s1 = 0l;
        for (int i=0; i<n1; i++) {
            s1 = s1 + (long long)a[c--];
        }
        s2 = 0l;
        for (int i=0; i<n2; i++) {
            s2 = s2 + (long long)a[c--];
        }
        ans = s1 * ln2 + s2 * ln1;
    }
    {
        long long s1, s2;
        int c = n-1;
        s2 = 0l;
        for (int i=0; i<n2; i++) {
            s2 = s2 + (long long)a[c--];
        }
        s1 = 0l;
        for (int i=0; i<n1; i++) {
            s1 = s1 + (long long)a[c--];
        }
        ans = maxll(ans, s1 * ln2 + s2 * ln1);
    }

    long long d = ln1 * ln2;
    printf("%f", (double)ans/(double)d);
    return 0;
}
