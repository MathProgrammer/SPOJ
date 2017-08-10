#include <cstdio>
#include <vector>

using namespace std;

vector <int> prime;

void precompute_primes()
{
    const int limit = 50000;

    vector <int> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= limit; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*1LL*i; multiple <= limit; multiple += i)
            {
                is_prime[multiple] = false;
            }
            prime.push_back(i);
        }
    }
}

void solve()
{
    int n;
    scanf("%d", &n);

    const int MOD = 1e9 + 7;
    long long no_of_divisors = 1LL;

    for(int prime_counter = 0; prime[prime_counter] <= n; prime_counter++)
    {
        int exponent_i = 0, prime_i = prime[prime_counter];
        int prime_i_power = prime_i;

        while(prime_i_power <= n)
        {
            exponent_i += n/prime_i_power;
            prime_i_power *= prime_i;
        }

        no_of_divisors *= (exponent_i + 1)%MOD;
        no_of_divisors = no_of_divisors%MOD;
    }

    printf("%lld\n", no_of_divisors);
}

int main()
{
    precompute_primes();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
