#include <cstdio>
#include <vector>

using namespace std;

vector <int> prime;

void precompute_primes()
{
    vector <int> is_prime(1e6 + 1,true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 1e6; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*1LL*i; multiple <= 1e6; multiple += i)
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

    int original_n = n;
    long long phi_n = 1LL, prime_product = 1LL;

    for(unsigned int i = 0; prime[i]*1LL*prime[i] <= n; i++)
    {
        if(n%prime[i] == 0)
        {
            prime_product = prime_product*prime[i];
            phi_n = phi_n*(prime[i] - 1);

            while(n%prime[i] == 0)
            {
                n = n/prime[i];
            }
        }
    }

    if(n > 1)
    {
        prime_product = prime_product*n;
        phi_n = phi_n*(n - 1);
    }

    phi_n = phi_n*(original_n/prime_product);

    printf("%lld\n", phi_n);
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
