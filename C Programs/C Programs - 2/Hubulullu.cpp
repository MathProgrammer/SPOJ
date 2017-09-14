#include <cstdio>

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int n, first_player;
        scanf("%d %d", &n, &first_player);

        printf(first_player == 0 ? "Airborne wins.\n" : "Pagfloyd wins.\n");
    }

    return 0;
}
