#include <bits/stdc++.h >
using namespace std;
int n;
char s[1000005];
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    int l = 0, r = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') l++;
        else r++;
    }
    if (r != l) {
        printf("-1\n");
        return 0;
    }
    l = 0;
    r = 0;
    int ans = 0;
    stack<int> stk;
    for (int i=0; i<n; i++) {
        if (r != 0) {
            if (s[i] == '(') {
                l++;
            } else {
                r++;
            }
            if (l == r) {
                ans += (r+l);
                l = 0;
                r = 0;
            }
        } else {
            if (s[i] == '(')
            {
                stk.push(1);
            }
            else
            {
                if (stk.size() != 0) {
                    stk.pop();
                } else {
                    r = 1;
                    l = 0;
                }
            }
        }
    }
    printf("%d\n", ans);
}