#include <bits/stdc++.h>

using namespace std;
set<int> ans;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        ans.clear();
        for (int i=1; i<=(int)(sqrt(n)); i++){
            if (ans.count(i) == 0 && ans.count(n/i) == 0) {
                ans.insert(i);
                ans.insert(n/i);
            }
        }
    ans.insert(0);
    printf("%d\n", ans.size());
    for (set<int>::iterator i=ans.begin(); i!=ans.end(); i++) {
        printf("%d ", *i);
    }
    printf("\n");
    }
}
