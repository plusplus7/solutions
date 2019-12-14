
#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int l=0,r=0,d=0,u=0;
        scanf("%s", s);
        for (int i=0; s[i]; i++) {
            if (s[i] == 'L') l++;
            if (s[i] == 'R') r++;
            if (s[i] == 'D') d++;
            if (s[i] == 'U') u++;
        }
        int minlr = min(l, r);
        int mindu = min(d, u);
        if (minlr == 0 && mindu == 0) {
            printf("0\n\n");
            continue;
        }
        if (minlr == 0 && mindu > 0) {
                printf("2\nDU\n");
            continue;
        }
        if (mindu == 0 && minlr > 0) {
             printf("2\nLR\n");
            continue;
        }
        int ans = minlr*2 + mindu*2;
        printf("%d\n", ans);
            for (int i=0; i<minlr; i++) {
                printf("%c", 'R');
            }
            for (int i=0; i<mindu; i++) {
                printf("%c", 'U');
            }
            for (int i=0; i<minlr; i++) {
                printf("%c", 'L');
            }
            for (int i=0; i<mindu; i++) {
                printf("%c", 'D');
            }
            printf("\n");
    }
}
