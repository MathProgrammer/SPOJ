#include <stdio.h>
#include <vector>

using namespace std;

vector <int> at_least_three_prime_factors;

void precompute_prime_factors()
{
    vector <int> no_of_prime_factors(3000 + 1, 0);

    for(int i = 2; i <= 3000; i++)
        if(no_of_prime_factors[i] == 0)
            for(int multiple = i; multiple <= 3000; multiple += i)
            {
                no_of_prime_factors[multiple]++;
            }

    for(int i = 2; i <= 3000 && at_least_three_prime_factors.size() <= 1000; i++)
        if(no_of_prime_factors[i] >= 3)
            at_least_three_prime_factors.push_back(i);

}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_prime_factors();

    while(no_of_test_cases--)
    {
        int query;
        scanf("%d", &query);

        printf("%d\n",at_least_three_prime_factors[query - 1]);
    }

    return 0;
}
