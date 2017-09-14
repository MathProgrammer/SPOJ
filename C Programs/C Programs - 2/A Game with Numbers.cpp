#include <cstdio>

int main()
{
    long long n;
    scanf("%lld", &n);

    printf(n%10 == 0 ? "2\n" : "1\n%d\n",n%10);
    return 0;
}
