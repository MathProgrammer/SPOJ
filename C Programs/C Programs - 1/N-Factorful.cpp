#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > sum_of_n_prime_factors(1e6 + 1, vector <int> (10 + 1, 0));

void precompute_prime_factors()
{
    vector <int> no_of_distinct_prime_factors(1e6 + 1, 0);

    for(int i = 2; i <= 1e6; i++)
    {
        if(no_of_distinct_prime_factors[i] == 0)
        {
            for(int j = i; j <= 1e6; j +=i)
            {
                no_of_distinct_prime_factors[j]++;
            }
        }
    }

    for(int i = 1; i <= 1e6; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            sum_of_n_prime_factors[i][j] = sum_of_n_prime_factors[i - 1][j];
        }
        sum_of_n_prime_factors[i][no_of_distinct_prime_factors[i] ]++;
    }

}

void solve()
{
    int a, b, left, right, n;
    scanf("%d %d %d", &a, &b, &n);

    left = min(a, b);
    right = max(a, b);

    printf("%d\n", sum_of_n_prime_factors[right][n] - sum_of_n_prime_factors[left - 1][n]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_prime_factors();

    while(no_of_test_cases--)
        solve();

    return 0;
}
