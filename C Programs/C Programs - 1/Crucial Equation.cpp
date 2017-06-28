#include <cstdio>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    for(int i = 1; i <= no_of_test_cases; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        printf("Case %d: ",i);
        printf(c%gcd(max(a, b), min(a, b)) == 0 ? "Yes\n" : "No\n");
    }
    return 0;
}
