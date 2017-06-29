#include <cstdio>
#include <vector>

using namespace std;

vector <int> eligible_primes;
vector <vector <int> > no_of_ways_to_make(8000 + 1, vector <int> (4 + 1, 0));

void precompute_primes()
{
    const int limit = 8000;
    vector <int> is_prime(limit + 1,true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= limit; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= limit; multiple += i)
            {
                is_prime[multiple] = false;
            }

            if(i%4 != 3)
                eligible_primes.push_back(i); //2 and all primes congruent 1 mod 4.
        }
    }
}

void precompute_no_of_summing_ways()
{
    int coin_value[4] = {0, 1, 2, 3};
    const int no_of_coins = 4;

    for(int coin_no = 1; coin_no < no_of_coins; coin_no++)
    {
        no_of_ways_to_make[0][coin_no] = 1;
    }

    for(int coin_no = 1; coin_no < no_of_coins; coin_no++)
    {
        for(int sum = 1; sum <= 8000; sum++)
        {
            if(sum >= coin_value[coin_no])
            {
                no_of_ways_to_make[sum][coin_no] = no_of_ways_to_make[sum][coin_no - 1] //Don't use current coin

                                                    + no_of_ways_to_make[sum - coin_value[coin_no] ][coin_no]; //Use current coin
            }
            else
            {
                no_of_ways_to_make[sum][coin_no] = no_of_ways_to_make[sum][coin_no - 1];
            }
        }
    }
}

int main()
{
    precompute_primes();
    precompute_no_of_summing_ways();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", no_of_ways_to_make[ eligible_primes[a - 1] ][b]);
    }
    return 0;
}
