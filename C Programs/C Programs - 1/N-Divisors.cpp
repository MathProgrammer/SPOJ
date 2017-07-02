#include <cstdio>
#include <vector>

using namespace std;

vector <int> prime;

void precompute_primes()
{
    vector <int> is_prime(1e5 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < 1e5; i++) //Numbers greater than 1e3 will not have unmarkes multiples smaller than 1e5 .. i^2 is smallest unmarked.
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple < 1e5; multiple +=i)
            {
                is_prime[multiple] = false;
            }
            prime.push_back(i);
        }
    }

}

int divisor_count(int n)
{
    int no_of_divisors = 1;

    for(int p = 0; prime[p]*prime[p] <= n; p++)
    {
        int exponent = 0;

        if(n%prime[p] == 0)
        {
            while(n%prime[p] == 0)
            {
                n /= prime[p];
                exponent++;
            }
            no_of_divisors *= (exponent + 1); //Number of divisors = (a1 + 1)(a2 + 1) ... (an + 1)
        }

    }

    if(n > 1)
            no_of_divisors = (no_of_divisors*2); //n has 1 prime factor greater than it's square root.

    return no_of_divisors;
}
int main()
{
    precompute_primes();

    int a, b, n, no_of_n_divisors = 0;
    scanf("%d %d %d", &a, &b, &n);

    for(int i = a; i <= b; i++)
        no_of_n_divisors += (divisor_count(i) == n);


    printf("%d\n", no_of_n_divisors);

    return 0;
}
