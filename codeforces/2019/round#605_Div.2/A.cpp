#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (abs(b-a) <= 1 && abs(c-a) <= 1 ||
            abs(b-c) <= 1 && abs(a-c) <= 1 ||
            abs(c-b) <= 1 && abs(a-b) <= 1 )
        {
            printf("%d\n", 0);
        } else {
            printf("%d\n", abs(a-b) + abs(a-c) + abs(b-c) - 4);
        }
    }
    return 0;
}
