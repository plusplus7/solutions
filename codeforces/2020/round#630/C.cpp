#include <bits/stdc++.h >
using namespace std;

int cnt[200005][26];
char s[200005];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s);

        for (int i=0; i<n; i++) {
                for (int j=0; j<26; j++) {
                    cnt [i][j] = 0;
                }

                }

        for (int i=0; i<n; i++) {
            int x = i%k;
            cnt[x][s[i]-'a'] ++;
        }
        int ans = 0;
        for (int i=0; i<k/2; i++) {
            int v = k-i-1;
            int all = 0;
            int m = 0;
            for (int j=0; j<26; j++) {
                cnt[i][j] += cnt[v][j];
                all += cnt[i][j];
                m = max(cnt[i][j], m);
            }
            ans += all-m;
        }
        if (k&1) {
            int all = 0;
            int m = 0;
            int xx= k/2;
            for (int j=0; j<26; j++) {
                all += cnt[xx][j];
                m = max(cnt[xx][j], m);
            }
            ans += all-m;
        }


        cout << ans << endl;
    }
    return 0;
}
