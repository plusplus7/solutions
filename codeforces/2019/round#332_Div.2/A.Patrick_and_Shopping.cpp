#include <iostream>
using namespace std;

int maxd(int a, int b)
{
    return a>b?b:a;
}
int main()
{
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    int a1 = d1 + d3 + d2;
    int a2 = d1 + d1 + d2 + d2;
    int a3 = d2 + d3 + d1;
    int a4 = d2 + d2 + d1 + d1;
    int a5 = d1 + d3 + d3 + d1;
    int a6 = d2 + d3 + d3 + d2;

    int ans = maxd(a1, maxd(a2, maxd(a3, maxd(a4, maxd(a5, a6)))));
    cout <<  ans << endl;
}
