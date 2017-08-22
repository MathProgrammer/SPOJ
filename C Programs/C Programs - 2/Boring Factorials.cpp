#include <cstdio>

long long power_mod(int x, int power, int mod)
{
    long long result = 1, y = x;

    while(power > 0)
    {
        if(power%2 == 1)
            result = (result*y)%mod;

        y = (y*y)%mod;
        power = power >> 1;
    }

    return result;
}

long long inverse_by_fermat_theorem(int n, int prime)
{
    return power_mod(n, prime - 2, prime);//a^(p - 1) = 1 (mod p) => a^(p - 2) = a^(-1) (mod p)
}

long long wilson_theorem_factorial(int n, int prime)
{
    //(p - 1)! = -1 (mod p) => (p - 2)! = -1.(inverse(p-1)) (mod p), => (p - 3)! = -1. (p - 1)^(-1). (p - 2)^(-1) and so on till we reach n
    long long factorial = prime - 1; //p - 1 = -1 (mod p)

    if(n >= prime)
    {
        factorial = 0; //prime divides factorial
        return factorial;
    }

    long long product = 1;
    for(int i = prime - 1; i > n; i--)
    {
        product = (product*i)%prime;
    }

    factorial = (factorial*inverse_by_fermat_theorem(product, prime))%prime;

    return factorial;
}

void solve()
{
    int n, prime;
    scanf("%d %d", &n, &prime);

    long long answer = 1;

    answer = wilson_theorem_factorial(n, prime);

    printf("%lld\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
