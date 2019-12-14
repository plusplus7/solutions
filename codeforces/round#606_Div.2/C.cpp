#include <bits/stdc++.h>
using namespace std;
char s[150005];
int ans[150005];
int la = 0;
char p1[4] = "one";
char p2[4] = "two";
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        la = 0;
        for (int i=0; s[i]; i++) {
           //     printf("->%c\n", s[i]);
            if (s[i] == 'o') {
                int ni = i;
                for (int j=0; p1[j]; j++) {
                    if (s[i+j] == '\0' || s[i+j] != p1[j]) {
                        ni = -1;
                        break;
                    } else {
                        ni++;
                    }
                }

                if (ni != -1) {
                    ni--;
                ans[la++] = (i+1);
     //   printf("1->%d\n", i+1);
                    i = ni;
                    continue;
                }
            }
            if (s[i] == 't') {
                int ni = i;
                for (int j=0; p2[j]; j++) {
                 //       printf("%c\n", s[i+j]);
                    if (s[i+j] == '\0' || s[i+j] != p2[j]) {
                        ni = -1;break;
                    } else {
                        ni++;
                    }
                }

                if (ni != -1) {
                    ni--;
                    int on = 0;
                    while (s[ni] == 'o') {
                        ni++;
                        on++;
                    }
                    ni--;
                    if (on == 1) {
                        ans[la++] = (ni);
                  //      printf("2->%d\n", ni);

                    } else {
                        ans[la++] = (i+1);
                  //      printf("3->%d\n", i+1);

                        if (s[ni+1] != '\0' && s[ni+1] == 'n')
                            if (s[ni+2] != '\0' && s[ni+2] == 'e') {
                                ans[la++] = (ni+1);
                     //           printf("4->%d\n", ni+1);
                                ni = ni+2;
                        }
                    }
                    i = ni;
                    continue;
                }
            }
        }
        printf("%d\n", la);
        for (int i=0; i<la; i++) {
            printf("%d ", ans[i]+1);
        }
        printf("\n");
    }
}
