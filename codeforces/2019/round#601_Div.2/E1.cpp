#include <bits/stdc++.h>

using namespace std;

int n, prime[100005];
vector<int> a;

void eratosthenes(int upperbound){
	prime[0]=prime[1]=1;

	for(int i=2; i<=sqrt(upperbound); ++i)
	    if(prime[i] == 0)
		    for(int j=i*i; j<=upperbound; j+=i)
			    prime[j] = 1;
}

long long solve()
{
    long long mans = -1;
    int as = a.size();
    for (int i=2; i<=as; i++) {
        long long tm = 0;
        if (prime[i] == 0 && as%i == 0) {
            int mx = i/2, bat = 0;
            for (int j=0; j<as; j++) {
                if (j == bat+i) {
                    bat+=i;
                }
                tm += (long long)abs(a[bat+mx] - a[j]);
           // cout << bat << " " << j << " " << tm << endl;
            }
            if (mans == -1 || tm < mans) {
                mans = tm;
            }
        }
    }
    return mans;
}

int main()
{
    scanf("%d", &n);
    eratosthenes(n);
    a.clear();
    for (int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            a.push_back(i);
        }
    }
    if (n == 1 || a.size() == 1) {
        printf("-1\n");
    } else {
        cout << solve() << endl;
    }
    return 0;
}
