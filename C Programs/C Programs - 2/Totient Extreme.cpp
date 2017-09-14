#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &totient, int LIMIT)
{
    vector <int> largest_prime_factor_of(LIMIT + 1, 0);

    totient[1] = 1;
    for(int i = 2; i <= LIMIT; i++)
    {
        if(largest_prime_factor_of[i] == 0)
        {
            totient[i] = i - 1;

            for(int j = 2*i; j <= LIMIT; j += i)
                largest_prime_factor_of[j] = i;
        }
        else
        {
            int reduced_i = i;
            int p = largest_prime_factor_of[i];
            int p_power_n = 1;

            while(reduced_i%p == 0)
            {
                reduced_i /= p;
                p_power_n *= p;
            }

            int p_power_n_minus_1 = p_power_n/p;

            totient[i] = (p_power_n - p_power_n_minus_1)*totient[reduced_i];
        }
    }
}

void compute(vector <long long>&totient_sum_till, vector <int> &totient, int LIMIT)
{
    for(int i = 1; i <= LIMIT; i++)
        totient_sum_till[i] = totient_sum_till[i - 1] + totient[i];
}

int main()
{
    const int LIMIT = 1e4;
    vector <int> totient(LIMIT + 1);

    precompute(totient, LIMIT);

    vector <long long> totient_sum_till(LIMIT + 1, 0);
    compute(totient_sum_till, totient, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int n;
        scanf("%d", &n);

        printf("%lld\n", totient_sum_till[n]*totient_sum_till[n]);
    }

    return 0;
}
