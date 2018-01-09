#include <bits/stdc++.h>
using namespace std;

int n, T;

struct Task {
    int a;
    int t;
    int c;
};

Task tk[200005];

bool cmp(Task a, Task b) {
    return a.t < b.t;
}

vector<int> ans;
int check(int x) {
    int ct = 0, at = 0;
    sort(tk + 1, tk + n + 1, cmp);
    ans.clear();
    for (int i = 1; i <= n; i++) {
        if (x <= tk[i].a) {
            ct += tk[i].t;
            at++;
            ans.push_back(tk[i].c);
            if (ct > T) {
                return 0;
            }
            if ( at == x) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &T);
    for (int i=1; i<=n; i++) {
        scanf("%d%d", &tk[i].a, &tk[i].t);
        tk[i].c = i;
    }
    int mx = n;
    int mi = 0;
    while (mi < mx) {
       // printf("%d %d\n", mi, mx);
        int mid = ((mx + mi) >> 1) + 1;
        if (check(mid)) {
            mi = mid;
        } else {
            mx = mid-1;
        }
    }
    check(mi);
    printf("%d\n", mi);
    if (mi == 0) {
        printf("0\n");
        return 0;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans.back());
    return 0;
}