#include <bits/stdc++.h>

using namespace std;
 char s[100005];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        if (s[0] == '?') {
            for (char p='a'; p<='c'; p++) {
                if (s[1] != p) {
                    s[0] = p;
                    break;
                }
            }
        }

        for (int i=1; s[i]; i++) {
            if (s[i] == '?') {
                for (char p='a'; p<='c'; p++) {
                    if (s[i-1] != p && s[i+1] != p) {
                        s[i] = p;
                        break;
                    }
                }
            }
        }
        int f = 1;
        for (int i=1; s[i]; i++) {
            if (s[i] == s[i-1]) {
                f=0;
                break;
            }
        }
        if (f == 1) {
             printf("%s\n", s);
        } else {
        printf("-1\n");
        }

    }
}
