#include <bits/stdc++.h>
using namespace std;

int p[1002];
vector<int> g[1002];

int f;
int check(int x)
{
    if (g[x].size() == 0) {
        return 1;
    }
    int cnt = 0;
    for (unsigned int i=0; i<g[x].size(); i++) {
        int v = check(g[x][i]);
        cnt += v;
    }
    if (cnt < 3) {
        f = 0;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    cout << 10000000 % (long long)pow(n, 100000000)<< endl;
    for (int i=1; i<=n; i++) {
        g[i].clear();
    }
    for (int i=2; i<=n; i++) {
        scanf("%d", p+i);
        g[p[i]].push_back(i);
    }
    f = 1;
    check(1);
    printf("%s\n", f ? "Yes" : "No");
    return 0;
}