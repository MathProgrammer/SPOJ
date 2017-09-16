#include <cstdio>
#define min(a, b) (a < b ? a : b)

long long combination(int n, int r)
{
    long long result = 1;

    r = min(r, n - r);

    for(int i = 0; i < r; i++)
    {
        result = (result*(n - i))/(i + 1);
    }
    return result;
}


int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        printf("%lld\n", combination(n - 1, k - 1));
    }

    return 0;
}
