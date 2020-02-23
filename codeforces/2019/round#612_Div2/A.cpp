#include <bits/stdc++.h>
using namespace std;

int main() {
    int cas;
    scanf("%d", &cas);

    while (cas--) {
        int k;
        scanf("%d", &k);
        char s[105];
        scanf("%s", s);
        int ans = 0;
        while (true) {
            int f = 0;
            for (int i=0; i<k-1; i++) {
                if (s[i] == 'A' && s[i+1] == 'P') {
                    s[i+1] = 'A';
                    i++;
                    f = 1;
                }
            }
            if (f == 0) {
                break;
            }
            ans ++;
        }
        printf("%d\n", ans);
    }
}