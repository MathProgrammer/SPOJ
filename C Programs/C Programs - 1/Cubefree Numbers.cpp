#include <stdio.h>
#include <vector>

using namespace std;

vector <int> is_cubefree(1e6 + 1, true);
vector <int> cubefree_numbers_index(1e6 + 1, 0);

void precompute_cubefree_numbers()
{
	vector <int> is_prime(100 + 1, true);
    for(int i = 2; i <= 100; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= 100; multiple += i)
            {
                is_prime[multiple] = false;
            }

            for(int cubes = i*i*i; cubes <= 1e6; cubes += i*i*i)
            {
                is_cubefree[cubes] = false;
            }
        }
    }

    int cubefree_index = 1;
    for(int i = 1; i <= 1e6; i++)
    {
        if(is_cubefree[i])
        {
            cubefree_numbers_index[i] = cubefree_index;
            cubefree_index++;
        }
    }
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_cubefree_numbers();

    for(int i = 1; i <= no_of_test_cases; i++)
    {
        int query;
        scanf("%d", &query);

        printf("Case %d: ", i);
        printf(is_cubefree[query] == false ? "Not Cube Free\n" : "%d\n",cubefree_numbers_index[query]);
    }

    return 0;
}
