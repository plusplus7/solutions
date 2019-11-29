#include <bits/stdc++.h>

using namespace std;

int mp[30][30];
int c[30];
int tt[30];
void dfs(int x, int color) {
    for (int i=0; i<26; i++) {
        if (mp[x][i] == 1 && c[i] == 0) {
            c[i] = color;
            dfs(i, color);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(tt, 0,sizeof(tt));
    memset(mp, 0, sizeof(mp));
    for (int i=0; i<n; i++) {
        char s[100];
        scanf("%s", s);
        int t[30];
        memset(t, 0,sizeof(t));
        for (int j=0; s[j]; j++) {
            int x = s[j]-'a';
            t[x] = 1;
            tt[x] = 1;
        }
        for (int j=0; j<26; j++) {
            if (t[j] == 1) {
                for (int k=0; k<26; k++) {
                    if (t[k] == 1) {
                        mp[j][k] = 1;
                        mp[k][j] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    memset(c, 0, sizeof(c));
    for (int i=0; i<26; i++) {
        if (tt[i] != 0 && c[i] == 0) {
            ans++;
            c[i] = ans;
            dfs(i, ans);
        }
    }
    printf("%d\n", ans);
}
