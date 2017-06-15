#include <stdio.h>

int reverse(int number)
{
    const int base = 10;
    int reverse = 0;

    while(number > 0)
    {
        reverse = reverse*base + (number%base);
        number /= base;
    }

    return reverse;
}
void solve()
{
    int num_1, num_2;
    scanf("%d %d",&num_1, &num_2);

    printf("%d\n",reverse( reverse(num_1) + reverse(num_2) ));
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
