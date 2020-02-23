#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b)
{
    a = b-a;
    a = a<0?-a:a;
    int c = a%5;
    c = c==4?2:
            c==3?2:
                c==2?1:
                    c==1?1:0;
    return a/5 + c;
}

int main()
{
    int T;
    cin >> T;
    while (T--){
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
