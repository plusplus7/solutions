#include <iostream>
#include <cstdio>

using namespace std;

int s[100005], k, n;

int check(int x)
{
    int r = n-1, l = 0, cnt = 0;
    while (r >= l && cnt != k) {
        if (s[r] <= x && r == l) {
            cnt++;
            r--;
            continue;
        }
        if (x < s[r]) {
            return 1;
        }
        if (x >= s[r]+s[l]) {
            cnt++;
            r--;
            l++;
        } else {
            cnt++;
            r--;
        }
    }
    if (r < l && cnt <= k) {
        return 0;
    }
    return 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", s+i);
    }

    int r = 2000005, l = 1, mid;

    while (r > l) {
        mid = (r+l)>>1;
        if (!check(mid)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    printf("%d\n", r);
}
