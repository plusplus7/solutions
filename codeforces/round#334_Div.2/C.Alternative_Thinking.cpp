#include <cstdio>

using namespace std;

char s[100005];
int min(int x, int y)
{
    return x > y ? y : x;
}
int main()
{
    int n;
    int cnt = 0;
    scanf("%d", &n);
    scanf("%s", s);

    for (int i=1; s[i-1]; i++) {
        if (s[i] == '\0' || s[i] != s[i-1]) {
            cnt++;
        }
    }
    printf("%d\n", min(cnt+2, n));
}
