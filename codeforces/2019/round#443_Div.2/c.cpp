#include <bits/stdc++.h>
using namespace std;

int a[10];
int main() {
    int n, t;
    char c;
    for (int i=0; i<10; i++) {
        a[i] = 7;
    }

    scanf("%d%*c", &n);
    while (n--) {
        scanf("%c %d%*c", &c, &t);
        if (c == '|') {
            for (int i=0; i<10; i++, t>>=1) {
                int lt = t&1;
                if (lt == 1) {
                    a[i] = 1;
                }
            }
        } else if (c == '&') {
            for (int i=0; i<10; i++, t>>=1) {
                int lt = t&1;
                if (lt == 0) {
                    a[i] = 0;
                }
            }
        } else {
            for (int i=0; i<10; i++, t>>=1) {
                int lt = t&1;
                if (lt == 1) {
                    if (a[i] == 1 || a[i] == 0) {
                        a[i] = a[i]^lt;
                    } else {
                        a[i] = -a[i];
                    }
                } else {
                    if (a[i] == 1 || a[i] == 0) {
                        a[i] = a[i]^lt;
                    } else {
                        a[i] = a[i];
                    }
                }
            }
        }
    }
    printf("3\n");
    int xxor = 0;
    int xand = 0;
    int aor = 0;
    for (int i = 0; i < 10; i++)
    {
        xand += 1 << i;
        if (a[i] == -7)
        {
            xxor += 1 << i;
        }
        if (a[i] == 0)
        {
            xand -= 1 << i;
        }
        if (a[i] == 1)
        {
            aor += 1 << i;
        }
    }

    printf("^ %d\n", xxor);
    printf("| %d\n", aor);
    printf("& %d\n", xand);

    return 0;
}