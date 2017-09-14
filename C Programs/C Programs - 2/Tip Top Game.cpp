#include <cstdio>

int is_square(long long n)
{
    long long low = 1, high = 1e9;
    long long mid;

    while(low <= high)
    {
        mid = (low + high)/2;

        if(mid*mid == n)
            break;
        else if(mid*mid < n)
            low = mid + 1;
        else if(mid*mid > n)
            high = mid - 1;
    }

    return (mid*mid == n);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    for(int i = 1; i <= no_of_test_cases; i++)
    {
        long long n;
        scanf("%lld", &n);

        printf("Case %d: %s\n", i, is_square(n) ? "Yes" : "No");
    }

    return 0;
}
