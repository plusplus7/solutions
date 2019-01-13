#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-7;

int n;
double x[1000006];
double v[1000006];

double go(double m)
{
    double ms = 0;
    for (int i=0; i<n; i++) {
        double s = fabs(x[i]-m)/v[i];
        ms = s > ms ? s : ms;
    }
    return ms;
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lf", x+i);
    }
    for (int i=0; i<n; i++) {
        scanf("%lf", v+i);
    }

    double s = 1;
    double e = 1000000000;

    double ps = go(s);
    double pe = go(e);

    while (fabs(e-s) > eps) {
        double mid1 = s + (e-s)/3.0;
        double mid2 = s + ((e-s)/3.0)*2.0;
        double ts1 = go(mid1);
        double ts2 = go(mid2);
        
        if (ts1 > ts2) {
            s = mid1;
            ps = ts1;
        } else {
            e = mid2;
            pe = ts2;
        }
    }
    printf("%f\n", ps);
}
