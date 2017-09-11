#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &prime, int limit)
{
    vector <int> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= limit; i++)
    {
        if(is_prime[i])
        {
            prime.push_back(i);

            for(long long multiple = i*1LL*i; multiple <= limit; multiple +=i)
            {
                is_prime[multiple] = false;
            }
        }
    }
}

void solve(vector <int> prime)
{
    long long n;
    scanf("%lld", &n);

    int two_squares = true;
    for(int i = 0; prime[i]*1LL*prime[i] <= n; i++)
    {
        if(n%prime[i] == 0)
        {
            int exponent = 0;
            while(n%prime[i] == 0)
            {
                n = n/prime[i];
                exponent++;
            }

            if(prime[i]%4 == 3 && exponent%2 != 0)
                two_squares = false;
        }
    }

    if(n%4 == 3)
        two_squares = false;

    printf(two_squares ? "Yes\n" : "No\n");
}

int main()
{
    const int LIMIT = 1e6;
    vector <int> prime;
    precompute(prime, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve(prime);

    return 0;
}
