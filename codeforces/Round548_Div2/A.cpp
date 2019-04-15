#include <bits/stdc++.h>
using namespace std;
    int n;
    char str[65002];
int main() {
    int ans=0;
    scanf("%d", &n);
    scanf("%s", str);
    for (int i=0; i<n; i++) {
        int t = str[i] - '0';
        if ((t&1) == 0) {
            ans += (i+1);
        }
    }

    printf("%d\n", ans);
    return 0;
}
