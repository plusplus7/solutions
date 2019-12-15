#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int swap1 = -1, swap2 = -1;
        char s[5005], c[5005];
        scanf("%s%s", s, c);
        string ss(s),cc(c);
        if (ss < cc) {
            printf("%s\n", ss.c_str());
            continue;
        }
        for (int i = 0; i < ss.length(); i++)
        {
            for (int j = i + 1; j < ss.length(); j++)
            {
                if (ss[i] <= ss[j])
                    continue;
                swap(ss[i], ss[j]);
                if (ss < cc)
                {
                    swap1 = i;
                    swap2 = j;
                    break;
                }
                swap(ss[i], ss[j]);
            }
            if (swap1 != -1)
            {
                break;
            }
        }

        if (swap1 != -1)
        {
            printf("%s\n", ss.c_str());
        }
        else
        {
            printf("---\n");
        }
    }
    return 0;
}
