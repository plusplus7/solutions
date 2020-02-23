#include "bits/stdc++.h"

using namespace std;

int n;
int a[700];
int k;
int b[700];
int s[700];
int e[700];
int dp[700][700], mark[700][700];

int dfs(int c, int pr, int l, int r) {
    if (l == r) {
        return a[l];
    }
    int L = dfs(c, pr, l, mark[l][r]);
    int R = dfs(c, pr + 1, mark[l][r]+1, r);
    if (L > R) {
        printf("%d R\n", c + pr + 1);
    } else {
        printf("%d L\n", c + pr + 2);
    }
    return L+R;
}

void get_ans(int c, int l, int r) {
    dfs(c, 0, l, r);
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", a+i);
    }
    scanf("%d", &k);
    for (int i=1; i<=k; i++) {
        scanf("%d", b+i);
    }

    int tn = 1;
    for (int i=1; i<=k; i++) {
        int ts = tn;
        int tb = b[i];
        if (tn > n) {
            printf("NO\n");
            return 0;
        }
        while (tb > 0) {
            tb-=a[tn];
            tn++;
            if (tn > n) {
                break;
            }
        }
        if (tb != 0) {
            printf("NO\n");
            return 0;
        } else {
            s[i] = ts;
            e[i] = tn-1;
        }
    }
    if (tn != n+1) {
        printf("NO\n");
        return 0;
    }

    memset(dp, 0, sizeof(dp));
    memset(mark, 0, sizeof(mark));
    for (int i=1; i<=k; i++) {
        int l = e[i]-s[i]+1;
        for (int j=s[i]; j<=e[i]; j++) {
                dp[j][j] = a[j];
                mark[j][j] = -1;
        }
        for (int j=s[i]; j<=e[i]-1; j++) {
            if (a[j] != a[j+1]) {
                dp[j][j+1] = a[j] + a[j+1];
                mark[j][j+1] = j;
            }
        }
        for (int j=3; j<=l; j++) {
            for (int k=s[i]; k<=e[i]-j+1; k++) {
                int m;
                for (m=k; m<k+j; m++) {
                    if (dp[k][m] != 0 && dp[m+1][k+j-1] != 0 && dp[k][m] != dp[m+1][k+j-1]) {
                        dp[k][k+j-1] = dp[k][m] + dp[m+1][k+j-1];
                        mark[k][k+j-1] = m;
                        break;
                    }
                }
                if (m != k+j) {
                    break;
                }
            }
        }
    }
    for (int i=1; i<=k; i++) {
        if (dp[s[i]][e[i]] != b[i]) {
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    for (int i=1; i<=k; i++) {
        get_ans(i-1, s[i], e[i]);
    }
}
