#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    char s[1005];

    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int ls = strlen(s);
        if (ls >= 2 && (s[ls-1] == 'o' && s[ls-2] == 'p')) {
            printf("FILIPINO\n");
        } else if (ls >= 4 && ((s[ls-1] == 'u' && s[ls-2] == 's' && s[ls-3] == 'e' && s[ls-4] == 'd') ||
                    (s[ls-1] == 'u' && s[ls-2] == 's' && s[ls-3] == 'a' && s[ls-4] == 'm'))) {
            printf("JAPANESE\n");
        } else  {
            printf("KOREAN\n");
        }
    }
    return 0;

}
