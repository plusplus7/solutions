#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[10005];
int main() 
{
    scanf("%d%d", &n ,&k);
    for (int i=0; i<k; i++) {
        scanf("%d", a+i);    
    }
    sort(a, a+k);
    int r4 = n, r2 = 2*n, r1 = 0, rr1= 0;
    for (int i=k-1; i>=0; i--) {
        int t4 = a[i]/4;
        int t2 = (a[i]%4)/2;
        int t1 = a[i]&1;

        if (r4 >= t4)
        {
            r4 -= t4;
        }
        else
        {
            t4 -= r4;
            r4 = 0;
            t2 += t4 * 2;
        }
        if (r2 >= t2)
        {
            r2 -= t2;
        }
        else
        {
            t2 -= r2;
            r2 = 0;
            if (r4 >= t2)
            {
                r4 -= t2;
                r1 += t2;
            }
            else
            {
                t2 -= r4;
                r4 = 0;
                t1 += t2 * 2;
            }
        }

        if (r1 >= t1)
        {
            r1 -= t1;
        }
        else
        {
            rr1 += t1;
        }

        
    }
    if (r1 + r2 + r4 < rr1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}