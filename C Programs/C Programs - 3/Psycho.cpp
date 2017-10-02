#include <cstdio>
#include <vector>

using namespace std;

const int LIMIT = 1e7 + 1, ODD = 1, EVEN = 0;

int no_of_exponents[LIMIT][2];
int largest_prime_factor[LIMIT] = {0};

void precompute()
{
    for(int i = 2; i < LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int multiple = i; multiple < LIMIT; multiple += i)
                largest_prime_factor[multiple] = i;
        }

        int p = largest_prime_factor[i];
        int reduced_i = i, exponent_p = 0;

        while(reduced_i%p == 0)
        {
            reduced_i /= p;
            exponent_p++;
        }

        no_of_exponents[i][ODD] = no_of_exponents[reduced_i][ODD] + (exponent_p%2 == 1);
        no_of_exponents[i][EVEN] = no_of_exponents[reduced_i][EVEN] + (exponent_p%2 == 0);
    }
}

int main()
{
    precompute();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int n;
        scanf("%d", &n);

        printf("%s\n", no_of_exponents[n][EVEN] > no_of_exponents[n][ODD] ? "Psycho Number" : "Ordinary Number");
    }

    return 0;
}
