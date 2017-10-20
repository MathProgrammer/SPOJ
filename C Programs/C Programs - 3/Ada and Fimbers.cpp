#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int get_mex(set <int> &state_possible)
{
    int i = 0;

    while(true)
    {
        if(state_possible.count(i) == 0)
            return i;

        i++;
    }
}

void compute(vector <int> &grundy, vector <int> &fibonacci, int MAX_STONES)
{
    grundy[0] = 0;

    for(int i = 1; i <= MAX_STONES; i++)
    {
        set <int> state_possible;

        for(int j = 0; fibonacci[j] <= i; j++)
        {
            state_possible.insert(grundy[i - fibonacci[j]]);
        }

        grundy[i] = get_mex(state_possible);
    }
}

int main()
{
    vector <int> fibonacci(35);
    fibonacci[0] = fibonacci[1] = 1;
    for(int i = 2; i < 35; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    const int MAX_STONES = 3e6;
    vector <int> grundy(MAX_STONES);
    compute(grundy, fibonacci, MAX_STONES);

    int no_of_piles;
    scanf("%d", &no_of_piles);

    int nim_sum = 0;
    while(no_of_piles--)
    {
        int stones;
        scanf("%d", &stones);

        nim_sum ^= grundy[stones];
    }

    printf(nim_sum == 0 ? "Vinit\n" : "Ada\n");
    return 0;
}
