#include <cstdio>

void solve()
{
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    for(int multiple = x; multiple <= n; multiple += x)
    {
        if(multiple%y != 0)
        {
            printf("%d ",multiple);
        }
    }
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
