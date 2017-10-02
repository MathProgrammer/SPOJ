#include <cstdio>

const int MAX_BITS = 100 + 4;
int total_strings[MAX_BITS][MAX_BITS] = {0};

void precompute()
{
    int no_of_strings[MAX_BITS][MAX_BITS][2] = {0};
    const int ZERO_FIRST = 0, ONE_FIRST = 1;

    no_of_strings[1][0][ZERO_FIRST] = 1, no_of_strings[1][0][ONE_FIRST] = 1, total_strings[1][0] = 1 + 1;
    no_of_strings[1][1][ZERO_FIRST] = 0, no_of_strings[1][1][ONE_FIRST] = 0, total_strings[1][1] = 0 + 0;

    for(int i = 2; i < MAX_BITS; i++)
    {
        no_of_strings[i][0][ZERO_FIRST] = total_strings[i - 1][0];
        no_of_strings[i][0][ONE_FIRST] = no_of_strings[i - 1][0][ZERO_FIRST];
        total_strings[i][0] = no_of_strings[i][0][ZERO_FIRST] + no_of_strings[i][0][ONE_FIRST];

        for(int set_bits = 1; set_bits < i; set_bits++)
        {
            no_of_strings[i][set_bits][ZERO_FIRST] = total_strings[i - 1][set_bits];
            no_of_strings[i][set_bits][ONE_FIRST]  = no_of_strings[i - 1][set_bits][ZERO_FIRST] + no_of_strings[i - 1][set_bits - 1][ONE_FIRST];

            total_strings[i][set_bits] = no_of_strings[i][set_bits][ZERO_FIRST] + no_of_strings[i][set_bits][ONE_FIRST];
        }
    }
}

int main()
{
    precompute();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int test_i, no_of_bits, no_of_set_bits;
        scanf("%d %d %d", &test_i, &no_of_bits, &no_of_set_bits);
        printf("%d %d\n", test_i, total_strings[no_of_bits][no_of_set_bits]);
    }

    return 0;
}
