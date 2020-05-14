#include <bits/stdc++.h>
using namespace std;

int s[100005];
int dp[100005];
int n;
void solve()
{
    int ans = 1;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    scanf("%d", &s[1]);
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        scanf("%d", s+i);
        dp[i] = 1;
        int sqrti = sqrt(i);
        for (int j=1; j<=sqrti; j++) {
            if (i%j == 0) {
                if (s[i] > s[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                int k = i/j;
                if (s[i] > s[k]) {
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);

}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}