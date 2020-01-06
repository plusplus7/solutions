#include <bits/stdc++.h>
using namespace std;

int n,m;
int q;
char s[50][20], t[50][20];
int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%s", s[i]);
    }
    for (int i=0; i<m; i++) {
        scanf("%s", t[i]);
    }
    scanf("%d", &q);
    while (q--) {
        int query;
        scanf("%d", &query);
        query--;
        printf("%s%s\n", s[query%n], t[query%m]);
    }
    return 0;

}
