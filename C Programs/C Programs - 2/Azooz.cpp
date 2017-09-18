#include <cstdio>

void solve()
{
    int no_of_levels;
    scanf("%d", &no_of_levels);

    int no_of_triangles = (no_of_levels*(no_of_levels + 1))/2;
    int no_of_sticks = 3*no_of_triangles;

    printf("%d\n", no_of_sticks);
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    for(int i = 1; i <= no_of_test_cases; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
