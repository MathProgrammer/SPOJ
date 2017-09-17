#include <cstdio>
#include <vector>

using namespace std;

void solve(int test_i)
{
    int no_of_bushes, maximum_berries;
    scanf("%d %d", &no_of_bushes, &maximum_berries);

    vector <int> berries_on(no_of_bushes + 1, 0);
    for(int i = 1; i <= no_of_bushes; i++)
        scanf("%d", &berries_on[i]);

    typedef vector <int> v_int;
    vector <v_int> maximum_till(no_of_bushes + 1, v_int(maximum_berries + 1, 0));


    for(int remaining_berries = 1; remaining_berries <= maximum_berries; remaining_berries++)
        if(berries_on[1] <= remaining_berries)
            maximum_till[1][remaining_berries] = berries_on[1];

    for(int i = 2; i <= no_of_bushes; i++)
    {
        for(int remaining_berries = 1; remaining_berries <= maximum_berries; remaining_berries++)
        {
            maximum_till[i][remaining_berries] = maximum_till[i - 1][remaining_berries];

            if(berries_on[i] <= remaining_berries)
                maximum_till[i][remaining_berries] = max(maximum_till[i][remaining_berries],
                                                         berries_on[i] + maximum_till[i - 2][remaining_berries - berries_on[i]]);
        }
    }

    printf("Scenario #%d: %d\n", test_i, maximum_till[no_of_bushes][maximum_berries]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    for(int i = 1; i <= no_of_test_cases; i++)
        solve(i);


    return 0;
}
