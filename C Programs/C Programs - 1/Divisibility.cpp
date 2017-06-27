#include <stdio.h>

void solve()
{
    int multiple, limit, x, y;
    scanf("%d %d %d", &limit, &x, &y);

    multiple = x;
    for(multiple = x; multiple <= limit; multiple += x)
        if(multiple%y != 0)
            printf("%d ", multiple);

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
