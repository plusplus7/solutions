#include <cstdio>
#include <cstring>

char src[3000];
char tar[3000];
int dp_l[3000][3000], dp_r[3000][3000];
int main()
{
    scanf("%s", src);
    scanf("%s", tar);
    int ls = strlen(src);
    int lt = strlen(tar);
    for (int i=0; i<ls; i++) {
        dp_r[i][0] = dp_l[i][0] = tar[0] == src[i];
        dp_r[i][lt-1] = dp_l[i][lt-1] = tar[lt-1] == src[i];
    }
    for (int i=0; i<lt; i++) {
        dp_r[0][i] = dp_l[0][i] = tar[i] == src[0];
        dp_r[ls-1][i] = dp_l[ls-1][i] = tar[i] == src[ls-1];
    }
    for (int i=ls-1; i>=0; i--) {
        for (int j=lt-1; j>=0; j--) {
            dp_l[i][j] = (src[i] == tar[j])?dp_l[i+1][dp]:0;
        }
    }
}
