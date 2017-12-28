#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926;
struct point5d {
    double x[5];
};

int n;
point5d p[1005];

double mul(point5d a, point5d b) {
    double result = 0.0f;
    for (int i=0; i<5; i++) {
        result += a.x[i]*b.x[i];
    }
    return result;
}
double angle(point5d a, point5d b)
{
    return acos(mul(a, b) / (sqrt(mul(a, a)) * sqrt(mul(b, b))) );
}

point5d vector5d(point5d a, point5d b) {
    point5d result;
    for (int i=0; i<5; i++) {
        result.x[i] = b.x[i]-a.x[i];
    }
    return result;
}

int main() {
    point5d zero;
    for (int i=0; i<5; i++) {
        zero.x[i] = 0.0f;
    }

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<5; j++) {
            scanf("%lf", &(p[i].x[j]));
        }
    }

    vector<int> ans;
    ans.clear();
    for (int i=0; i<n; i++) {
        double max1 = -1.0;
        double max2 = -1.0;
        point5d a0 = vector5d(p[i], zero);
        vector<double> angles;
        angles.clear();
        for (int j=0; j<n; j++) {
            if (i == j) {
                continue;
            }

            point5d ab = vector5d(p[i], p[j]);

            angles.push_back(angle(a0, ab));
        }
        sort(angles.begin(), angles.end());

        int la = angles.size();
        int j;
        for (j = 0; j < la; j++)
        {
            int s1 = lower_bound(angles.begin(), angles.end(), PI / 2.0 - angles[j]) - angles.begin();
            if (s1 == la)
            {
                break;
            }
            int s2 = upper_bound(angles.begin(), angles.end(), PI * 1.5 - angles[j]) - angles.begin();
            if (s2 == s1 + 1 && s1 == j)
            {
                break;
            }
        }
        if (j == la)
        {
            ans.push_back(i+1);
        }
    }
    printf("%d\n", ans.size());
    for ( int i=0; i<ans.size(); i++){
        printf("%d\n", ans[i]);
    }

}
