#include <cstdio>
#include <vector>

using namespace std;

void precompute_answer(vector <long long> &answer)
{
    vector <int> smallest_prime_factor(1e7, 0);

    vector <int> is_prime(1e7 + 1, true);
    is_prime[0] = is_prime[1] = false;

    const int limit = 1e7;

    for(int i = 2; i <= limit; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = i; multiple <= limit; multiple += i)
            {
                if(smallest_prime_factor[multiple] == 0)
                    smallest_prime_factor[multiple] = i;

                is_prime[multiple] = false;
            }
        }
    }

    for(int i = 2; i <= limit; i++)
        answer[i] = answer[i - 1] + smallest_prime_factor[i];
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    vector <long long> answer(1e7 + 1, 0);
    precompute_answer(answer);

    while(no_of_test_cases--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", answer[n]);
    }

    return 0;
}
