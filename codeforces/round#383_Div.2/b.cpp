#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a[100005], b[100005];
int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    memset(b, 0, sizeof(b));
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
        b[a[i]]++;
    }
    long long ans = 0l;
    for (int i=0; i<n; i++) {
        if ((x^a[i]) > 100000) {
            continue;
        }
        ans += b[x^a[i]];
        if ((x^a[i]) == a[i]) {
            ans --;
        }
    }
    cout << ans/2l << endl;
}
