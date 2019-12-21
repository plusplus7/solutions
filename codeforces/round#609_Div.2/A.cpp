#include <bits/stdc++.h>

using namespace std;
bool prime(int n)
{
	for(int i = 2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i=4; i<=10e9; i++) {
        if (!prime(i) && !prime(n + i)) {
            cout << n + i << " "<< i<< endl;
            return 0;
        }
    }
}
