#include <bits/stdc++.h>
using namespace std;
int num[200005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", num + i);
    }

    int cur = num[n-1];
    long long ans = (long long)num[n-1];
    for (int i=n-2; i>=0; i--) {
        if (num[i] >= cur) {
            ans += (long long)(cur - 1);
        } else if (num[i] < cur && num[i] != 0){
            ans += (long long)(num[i]);
            cur = num[i];
        } else {
            break;
        }
        if (cur == 1) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}