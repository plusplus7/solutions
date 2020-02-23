#include <bits/stdc++.h>

using namespace std;
int n;
char s[4000005];
string as, ras;
set<string> st;
vector<int> c01, c10;
vector<int> s00, s11, s10, s01;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        st.clear();
        c01.clear();
        c10.clear();
        s01.clear();
        s10.clear();
        s11.clear();
        s00.clear();
        int n;
        scanf("%d", &n);
        for (int i=1; i<=n; i++) {
            scanf("%s", s);
            as = string(s);

            int ls = as.length();
            if (s[0] == '0' && s[ls-1] == '0') {
                s00.push_back(i);
                continue;
            }
            if (s[0] == '1' && s[ls-1] == '1') {
                s11.push_back(i);
                continue;
            }
            if (s[0] == '0' && s[ls-1] == '1') {
                s01.push_back(i);
            }
            if (s[0] == '1' && s[ls-1] == '0') {
                s10.push_back(i);
            }
            reverse(as.begin(), as.end());
            if (st.count(ras) == 0) {
                if (s[0] == '0' && s[ls-1] == '1') {
                    c01.push_back(i);
                }
                if (s[0] == '1' && s[ls-1] == '0') {
                    c10.push_back(i);
                }
            }
        }

        if (s00.size() != 0 && s11.size()  != 0 && (s10.size() == 0 || s01.size() == 0)) {
            printf("0\n");
            continue;
        }
        int l10 =s10.size();
        int l01 = s01.size();
        if ((l10-1) > l01) {
            int ans = ((l10)-l01)/2;

           //  printf("%d %d \n", l10-1, l01);

            printf("%d\n", ans);
            for (int i=0; i<ans; i++) {
                printf("%d ", s10[i]);
            }
        } else if ((l01-1) > l10) {
          //   printf("%d %d \n", (l01-1), l10);
            int ans = ((l01)-l10)/2;
            printf("%d\n", ans);
            for (int i=0; i<ans; i++) {
                printf("%d ", s01[i]);
            }
        } else {
            printf("0\n");
        }
    }
    return 0;
}
