#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    long long int x;
    double dx;
    cin >> x;
    dx = (double)x;
    double dx_3 = pow(dx, 1.0/3.0);
    long long int x_3 = (long long int)(dx_3*2);
    vector<long long int> ansl, ansr;
    ansl.clear();
    ansr.clear();
    for (long long int i=1; i<=x_3; i++) {
        if ((6*x+i*i*i-i)%(3*i*i+3*i) == 0) {
            long long int j = (6*x+i*i*i-i)/(3*i*i+3*i);
            if (j < i) {
                break;
            }
            ansl.push_back(i);
            ansr.push_back(j);
            if (j == i) {
                break;
            }
        }
    }
    cout << ansl.size()*2 - (ansl[ansl.size()-1] == ansr[ansr.size()-1]) << endl;
    for (int i=0; i<ansl.size(); i++) {
        cout << ansl[i] << " " << ansr[i] << endl;
    }
    for (int i=ansl.size()-1; i>=0; i--) {
        if (i == ansl.size()-1 && ansl[ansl.size()-1] != ansr[ansr.size()-1]) {
            cout << ansr[i] << " " << ansl[i] << endl;
        } else if (i != ansl.size()-1) {
            cout << ansr[i] << " " << ansl[i] << endl;
        }
    }
}
