#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, m, i, j, k, l;
    cin >> n >> m;
    int a[40][40];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=m; j++) {
            int k;
            for (k=1; k<=n; k++) {
                int cnt = 0;
                for (int l=1; l<=m; l++) {
                    if (l == i) {
                        if (a[k][j] != l) {
                            cnt++;
                        }
                        continue;
                    }
                    if (l == j) {
                        if (a[k][i] != l) {
                            cnt++;
                        }
                        continue;
                    }
                    if (l != a[k][l]) {
                        cnt++;
                    }
                }
                if (cnt != 2 && cnt != 0) {
                    break;
                }
            }
            if (k == n+1) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
