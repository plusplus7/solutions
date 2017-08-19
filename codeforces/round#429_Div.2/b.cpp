#include <bits/stdc++.h>
using namespace std;
int a[1000005];
long long sum = 0ll;
int main()
{
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
        if (a[i]%2 == 1) {
            flag = true;
        }
        sum += (long long)a[i];
    }
    if (sum % 2 == 1 || flag) {
        printf("First\n");
    } else {
        printf("Second\n");
    }
    return 0;
}
