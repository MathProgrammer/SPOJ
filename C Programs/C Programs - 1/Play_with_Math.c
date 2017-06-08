#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), (max(a, b)%min(a,b) ) );
}

void solve()
{
    int A, B, x, y, gcd_A_B;
    scanf("%d %d", &A, &B);

    gcd_A_B = gcd(A, B);

    x = B/gcd_A_B;
    y = A/gcd_A_B;

    printf("%d %d\n", x, y);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
