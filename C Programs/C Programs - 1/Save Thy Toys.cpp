#include <cstdio>
#include <vector>
#include <algorithm>

#define max_3(a, b, c) max(a, max( (b), (c) )
using namespace std;

void solve()
{
    int no_of_toys;
    scanf("%d", &no_of_toys);

    vector <int> cost(no_of_toys + 10);
    for(int i = 1; i <= no_of_toys; i++)
        scanf("%d", &cost[i]);

    vector <long long> maximum_saving_starting_from(no_of_toys + 10, 0);

    for(int i = no_of_toys; i >= 1; i--)
    {
        maximum_saving_starting_from[i] = max_3( (cost[i] + maximum_saving_starting_from[i + 2]), //Take one toy

                                                (cost[i] + cost[i + 1] + maximum_saving_starting_from[i + 4]), //Take two toys

                                                cost[i] + cost[i + 1] + cost[i + 2] + maximum_saving_starting_from[i + 6]) ); //Take three toys

    }

    printf("%lld\n", maximum_saving_starting_from[1]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
