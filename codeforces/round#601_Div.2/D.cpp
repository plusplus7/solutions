#include <bits/stdc++.h>

using namespace std;

char s[105][105], ans[105][105];
char lst[64] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int dir[4][2] = {  {0, 1}, {1,0},{0, -1}, {-1,0}};

void solve() {
    int r, c, k;
    int sr = 0;
    scanf("%d%d%d", &r, &c, &k);
    for (int i=0; i<r; i++) {
        scanf("%s", s[i]);
        for (int j=0; j<c; j++) {
            if (s[i][j] == 'R') {
               sr ++;

            }
            ans[i][j] = '-';
        }
    }

    int ex = sr%k, pe = sr/k, tk=0;

    char xk = lst[tk++];
    int xp = pe;
    if (ex > 0) {
        ex--;
        xp++;
    }

    int x =0, y=0, d=0;
    for (int i=0; i<r*c; i++) {
         //   printf("%d %d %d\n", d, x,y);
        if (s[x][y] == 'R') {
            xp--;
        }
        ans[x][y] = xk;
        if (xp == 0 && tk != k) {
            xk = lst[tk++];
            xp = pe;
            if (ex > 0) {
                ex--;
                xp++;
            }
        }
        int tx = x + dir[d][0];
        int ty = y + dir[d][1];
      //  cout << tx << " " << ty << " " << ans[tx][ty] << endl;
        if (tx >= r || tx < 0 || ty >= c || ty < 0 || ans[tx][ty] != '-') {
            d++;
            if (d == 4) d = 0;
        }
        x = x + dir[d][0];
        y = y + dir[d][1];
    }

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--){
        solve();
    }
}
