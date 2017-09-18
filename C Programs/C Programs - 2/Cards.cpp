#include <cstdio>

void solve()
{
    int no_of_levels;
    scanf("%d", &no_of_levels);

    const int MOD = 1e6 + 7;

    int last_level_cards = no_of_levels;

    long long no_of_triangles = (no_of_levels*1LL*(no_of_levels + 1) )/2;
    long long no_of_cards = 3*no_of_triangles - last_level_cards;
    no_of_cards %= MOD;

    printf("%I64d\n", no_of_cards);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
