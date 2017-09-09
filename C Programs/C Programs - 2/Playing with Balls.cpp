#include <cstdio>

void solve()
{
    int white_balls, black_balls;
    scanf("%d %d",&white_balls, &black_balls);

    printf("%s\n", black_balls%2 == 1 ? "1.000000" : "0.000000");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
